#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> mat;
    int height;
    int width;

public:
    Matrix(int _height, int _width) : height(_height), width(_width), mat(_height, std::vector<int>(_width, 0)) {}

    void set(int row, int col, int value) 
    {
        if (row >= 0 && row < height && col >= 0 && col < width)
            mat[row][col] = value;
    }

    void rotate90() {
        // סיבוב יוצר מטריצה חדשה בגובה = width, רוחב = height
        int new_width = height;
        int new_height = width;
        std::vector<std::vector<int>> rotated(new_width, std::vector<int>(new_height)); //Rotate +-90 deg!

        for (int h = 0; h < height; ++h) {
            for (int w = 0; w < width; ++w) {
                //rotated[width - 1 - w][w] = mat[h][w]; +90deg
                rotated[w][height - 1 - h] = mat[h][w]; // -90deg
                            //rotated[width - 1 - w][height - 1 - h] = mat[h][w]; // +180deg //new_width = width; new_height = heigt; no swop
            }
        }

        // החלפת המטריצה
        mat = rotated;
        std::swap(height, width);
    }

    void print() {
        for (const auto& row : mat) {
            for (int val : row)
                std::cout << val << " ";
            std::cout << "\n";
        }
    }

    int get_height() const { return height; }
    int get_width() const { return width; }
};
