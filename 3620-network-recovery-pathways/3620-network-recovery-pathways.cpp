class Solution
{
public:
    using u16 = uint16_t;
    using u32 = uint32_t;
    using u64 = uint64_t;

    struct Edge
    {
        u16 src;
        u16 dst;
        u32 cost;
    };

    inline static constexpr u32 kMaxNodes = 50'000;
    inline static constexpr u32 kMaxEdges = 100'000;
    inline static constexpr u32 kMaxLinks = 100'000;
    inline static constexpr u32 kMaxQueue = 50'001;

    inline static Edge edges[kMaxEdges];
    inline static u32 offset[kMaxNodes];
    inline static u16 degree[kMaxNodes];
    inline static u64 state[kMaxNodes];
    inline static u32 link_cost[kMaxLinks];
    inline static u16 link_dst[kMaxLinks];
    inline static u16 q[kMaxQueue];

    [[nodiscard, gnu::always_inline]] static bool
    is_possible(const u32 min_edge, const u16 n, const u64 k) noexcept
    {
        using std::views::drop;
        using std::views::iota;
        using std::views::take;
        u16 qs = 0, target = n - 1;
        const u64 g = k - min_edge;

        std::fill_n(state, n, (k + 1) << 1);
        state[0] = 1;
        q[qs++] = 0;

        while (qs)
        {
            auto i = q[--qs];
            u64 i_cost = state[i] >> 1;
            state[i] = i_cost << 1;  // reset 'queued' flag

            for (u32 li : iota(0u) | drop(offset[i]) | take(degree[i]))
            {
                u16 j = link_dst[li];
                u64 cost = i_cost + link_cost[li];
                bool b = link_cost[li] >= min_edge && cost < (state[j] >> 1);

                [[unlikely]] if (b & (j == target))
                {
                    return true;
                }

                b &= cost <= g;

                q[qs] = j;
                qs += b & !(state[j] & 1);
                state[j] =
                    (((cost << 1) | 1u) & -u64{b}) | (state[j] & -u64{!b});
            }
        }

        return false;
    };

    [[gnu::always_inline]]
    static u32 impl(const u64 k, const u32 num_edges, const u16 n) noexcept
    {
        using std::views::iota;
        using std::views::take;
        std::fill_n(offset, n, u32{});
        std::fill_n(degree, n, u16{});
        u32 min_edge = ~u32{}, max_edge = 0;

        for (auto& e : edges | take(num_edges))
        {
            ++degree[e.src];
            min_edge = std::min(min_edge, e.cost);
            max_edge = std::max(max_edge, e.cost);
        }

        for (u32 o = 0; u16 i : iota(u16{}, n))
        {
            offset[i] = o;
            o += std::exchange(degree[i], u32{});
        }

        for (auto& e : edges | take(num_edges))
        {
            u32 li = offset[e.src] + degree[e.src]++;
            link_cost[li] = e.cost;
            link_dst[li] = e.dst;
        }

        auto r = *std::ranges::upper_bound(
            iota(min_edge, max_edge + 1),
            true,
            std::greater{},
            std::bind(is_possible, std::placeholders::_1, n, k));
        return (r & -u32{r != min_edge}) - 1;
    }

    u32 findMaxPathScore(
        const std::vector<std::vector<int>>& in_edges,
        const std::vector<bool>& online,
        const u64 k) const noexcept
    {
        const auto n = static_cast<u16>(online.size());
        u32 num_edges = 0;
        for (const auto& e :
             reinterpret_cast<const std::vector<std::vector<u32>>&>(in_edges))
        {
            const auto i = static_cast<u16>(e[0]), j = static_cast<u16>(e[1]);
            edges[num_edges] = {.src = i, .dst = j, .cost = e[2]};
            // filter out edges with offline nodes and whose cost
            // is greater than k
            num_edges +=
                std::cmp_less_equal(e[2], k) && online[e[0]] && online[e[1]];
        }

        return impl(k, num_edges, n);
    }
};