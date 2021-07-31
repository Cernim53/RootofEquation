#include <iostream>

using namespace std;

class Uravneniya
{
protected:

	double a, b;

public:
    Uravneniya();
    virtual ~Uravneniya() {}
    virtual void RootofEquation() = 0;
};
Uravneniya::Uravneniya()
{
    cout << "Znach A = ";
    cin >> a;
    cout << "Znach B = ";
    cin >> b;
}

class LinUravneniya : Uravneniya
{
public:
    LinUravneniya();
    ~LinUravneniya() {}
    void RootofEquation() override;
};

LinUravneniya::LinUravneniya()
{
    cout << "Uravnenie vid " << a << "x + " << b << " = 0" << endl;
}

void LinUravneniya::RootofEquation()
{
    double x;

    x = -b / a;

    cout << "Koren raven x=" << x << endl << endl;
}

class KvadratUravneniya : Uravneniya
{
private:
    double c;

public:
    KvadratUravneniya();
    ~KvadratUravneniya() {}
    void RootofEquation() override;
};

KvadratUravneniya::KvadratUravneniya()
{
    cout << "Vvedite znachenie C = ";
    cin >> c;
    cout << "Uravnenie vid " << a << "x^2 + " << b << "x +" << c << " = 0" << endl;
}

void KvadratUravneniya::RootofEquation()
{
    double x1, x2;
    double d = b * b - 4 * a * c;
    if (d < 0)
    {
        cout << "Koren ne soderzet deystvikelnyh chisel" << endl << endl;
        return;
    }

    if (d == 0)
    {
        x1 = x2 = -b / (2 * a);
    }
    else if (d > 0)
    {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    }

    cout << "Korni uravneniya ravny x1=" << x1 << ", x2=" << x2 << endl << endl;
}

int main(int argc, char* argv[])
{
    LinUravneniya lU = LinUravneniya();
    lU.RootofEquation();

    KvadratUravneniya kU = KvadratUravneniya();
    kU.RootofEquation();

    return 0;
}