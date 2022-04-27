#include <iostream>
#include <fstream>

using namespace std;
string Rebuild(string str, string znaky)
{
    string rightPart = str;
    string result = "";
    int index = 0;
    int i = 1;

    while ((index = rightPart.find_first_of(znaky)) != -1)
    {
        while (isspace(rightPart[index - i]))
        {
            i++;
        }

        for (int j = 0; j < index - i + 1; j++)
        {
            result += rightPart[j];
        }
        result += rightPart[index];
        string c = "";
        c += rightPart[index + 1];
        while ((c.find_first_of(znaky)) == c[0])
        {
            result += rightPart[index++];
        }

        rightPart.erase(0, index + 1);
        i = 1;
    }

    result += rightPart;
    return result;
}
void Function(string fname)
{
    string str = "";
    ifstream f;
    f.open(fname);
    string tmp;
    while (!f.eof())
    {
        f >> tmp;
        str += tmp + " ";
    }

    tmp = "";


    f.close();
    char znaky[] = ",.:;!?";
    string result = Rebuild(str, znaky);
    ofstream of;
    of.open("t2.txt");
    of << result;
    of.close();

}

int main()
{
    string fname = "t1.txt";
    Function(fname);

    return 0;
}
