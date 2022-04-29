#include <iostream>
#include <cmath>
using namespace std;
namespace MatchVector
{
    struct Vector
    {
        float x{};
        float y{};
    };

    void PrintVector(const Vector &a){
        cout<<"("<<a.x<<", "<<a.y<<")"<<"\n";
    }

    Vector Add( const Vector &a, const Vector &b){
        Vector c{};
        c.x = a.x+b.x;
        c.y = a.y+b.y;
        return c;
    }

    Vector Subtract(const Vector &a, const Vector &b){
        Vector c{};
        c.x = a.x-b.x;
        c.y = a.y-b.y;
        return c;
    }

    void Scale(Vector &a, float scalar){
        a.x *= scalar;
        a.y *= scalar;
    }

    float Length(const Vector &a){

        return static_cast<float> (sqrt(fabs(pow(a.x, 2)) + fabs(pow(a.y, 2))));
    }

    void Normalize(Vector &a){

        float inv_length = 1.f/ Length(a);
        a.x *= inv_length;
        a.y *= inv_length;
    }
}

int main() {
    cout<<"Enter one of the operations on the vector"<<"\n";
    cout<<"add - Adding two vectors"<<"\n";
    cout<<"sub - Subtracting two vectors"<<"\n";
    cout<<"scale - Multiplying a vector by a scalar"<<"\n";
    cout<<"len - Finding the length of a vector"<<"\n";
    cout<<"norm - Vector normalization"<<"\n";
    cout<<":>";
    string answer;
    cin>>answer;
    if(answer == "add"){
        MatchVector::Vector a{};
        MatchVector::Vector b{};

        cout<<"Input vector A:"<<"\n";
        cin>> a.x>> a.y;
        cout<<"Input vector B:"<<"\n";
        cin>> b.x>> b.y;
        MatchVector::PrintVector(MatchVector::Add(a, b));

    }else if(answer == "sub"){
        MatchVector::Vector a{};
        MatchVector::Vector b{};

        cout<<"Input vector A:"<<"\n";
        cin>> a.x>> a.y;
        cout<<"Input vector B:"<<"\n";
        cin>> b.x>> b.y;
        MatchVector::PrintVector(MatchVector::Subtract(a, b));
    }else if(answer == "scale"){
        MatchVector::Vector a{};
        float scalar{};

        cout<<"Input vector:"<<"\n";
        cin>> a.x>> a.y;
        cout<<"Input scalar:"<<"\n";
        cin>> scalar;
        MatchVector::Scale(a, scalar);
        MatchVector::PrintVector(a);
    }else if(answer == "len"){
        MatchVector::Vector a{};

        cout<<"Input vector:"<<"\n";
        cin>> a.x>> a.y;
        cout<<MatchVector::Length(a)<<"\n";
    }else if(answer == "norm"){
        MatchVector::Vector a{};

        cout<<"Input vector:"<<"\n";
        cin>> a.x>> a.y;
        MatchVector::Normalize(a);
        MatchVector::PrintVector(a);
    }else{
        cout<<"Incorrect parameter"<<"\n";
    }
}