class Solution {

    double radius;
    double x_center;
    double y_center;

public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
        srand(time(0));
    }

    inline double randHelper()
    {
        return ((double) max(rand() - 1, 0)) / ((double) RAND_MAX);
    }

    vector<double> randPoint() {
        double r = radius * randHelper();
        double angle = M_PI * randHelper();

        return vector<double>( { x_center + r * cos(angle), y_center + r * sin(angle) } );
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
