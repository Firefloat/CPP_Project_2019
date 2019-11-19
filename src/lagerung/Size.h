#ifndef SRC_SIZE_H
#define SRC_SIZE_H

struct Size {

private:

public:
    double width_;
    double height_;
    double depth_;

    Size() {
        width_ = 0;
        height_ = 0;
        depth_ = 0;
    }

    Size(double width, double height, double depth) {
        width_ = width;
        height_ = height;
        depth_ = depth;
    }

};

#endif //SRC_SIZE_H
