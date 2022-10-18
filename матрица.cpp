#include <iostream>
#include <cstdlib>
using namespace std;
 
 struct vec3
{

    float x, y, z;

};

struct mat3
{

    vec3 x, y, z;
    float *operator[](std::ptrdiff_t const i) noexcept
    {
        return reinterpret_cast<float *>(&x + i);
    }
    float const *operator[](std::ptrdiff_t const i) const noexcept
    {
        return reinterpret_cast<float const *>(&x + i);
    }

};

struct Matrix
{
    float *data;
    std::size_t width,height;
};



void deleteMatrix(Matrix m){
    free(m.data);
}

void fill(Matrix m){
    float *data = m.data;
    std::size_t height = m.height;
    std::size_t width = m.width;
    for (std::size_t i=0;i<height;i++){
        for (std::size_t j=0;j<width;j++){
            data[i*width + j] = i+j;
        }
    }
}





Matrix createMatrix(std::size_t width,std::size_t height){
    Matrix m;
    m.data = static_cast<float *>(std::malloc(sizeof(float)*width*height));
    return m;
}





Matrix operator*(Matrix m1,Matrix m2){
    Matrix res = createMatrix(m2.width,m1.height);
    std::size_t height = m1.height;
    std::size_t width = m2.width;

    for (std::size_t i=0;i<height;i++){

        for (std::size_t j=0;j<width;j++){

            float r=0;
            for(std::size_t str=0;str<m1.width;str++){
                
                r += m1.data[i*m1.width + str]*m2.data[str*m2.width + j];
                
            }

            res.data[i*width + j] = r;

        }

    }
    return res;
}

/*


    1 2 3 4 5 

1   0 1 2 3 4 
2   5 6 7 8 9
3   10
4   
5   

*/










int main(){
    // Matrix m1 = createMatrix(4,3);
    // Matrix m2 = createMatrix(2,4);
    // for(int i = 0; i < 3; ++i)
    // for(int j = 0; j < 3; ++j)
    //     std::cin >> *m1.data(i*m1.width+j);
    
    // for(int i = 0; i < 3; ++i)
    // for(int j = 0; j < 3; ++j)
    //     std::cin >> *m2.data(i*m2.width+j);

    // Matrix res = createMatrix(2,3);
    // res = m1*m2;
    // for(int i = 0; i < 3; ++i)
    // for(int j = 0; j < 3; ++j)
    //     std::cout << res.data(i*res.width+j);
    //mat3 res = m1*m2;

    // cout << endl;
    // for(int i = 0; i < 3; ++i){
    // for(int j = 0; j < 3; ++j)
    //    std::cout << res[i][j] << " ";
    //    cout << endl;
    // }
}