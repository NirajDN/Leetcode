class Robot {
    int x; 
    int y;
    int width; 
    int height; 
    string dir; 
public:
    Robot(int width, int height) {
        x = 0, y = 0, dir = "East";
        this->width = width, this->height = height;
    }
    
    void step(int num) {
        num %= (2 * (width - 1) + 2 * (height - 1));
        if (num == 0) {
            num = (2 * (width - 1) + 2 * (height - 1));
        }

        while(num > 0) {
            int nx = x, ny = y; 
            
            if(dir == "East") {
                int maxX = min(x + num, width - 1); 
                int rem = num - (maxX - x); 
                num = rem; 
                if(rem == 0) {
                    x = maxX, y = ny; 
                } else {
                    x = maxX; 
                    dir = "North"; 
                }
            }
            else if(dir == "West") {
                int minX = max(x - num, 0); 
                int rem = num - (x - minX); 
                num = rem; 
                if(rem == 0) {
                    x = minX, y = ny; 
                } else {
                    x = minX; 
                    dir = "South"; 
                }
            }
            else if(dir == "North") {
                int maxY = min(y + num, height - 1); 
                int rem = num - (maxY - y); 
                num = rem; 
                if(rem == 0) {
                    x = nx, y = maxY; 
                } else {
                    y = maxY; 
                    dir = "West"; 
                }
            }
            else if(dir == "South") {
                int minY = max(y - num, 0); 
                int rem = num - (y - minY); 
                num = rem; 
                if(rem == 0) {
                    x = nx, y = minY; 
                } else {
                    y = minY; 
                    dir = "East"; 
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y}; 
    }
    
    string getDir() {
        return dir; 
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */