#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <utility>
#include <bits/stdc++.h>


using namespace std;
class Personne{
public:
    Personne(string name, string address, string number) : name(std::move(name)), address(std::move(address)),
                                                                                number(std::move(number)) {
    }
    string get_name() const {
        return name;
    }

    void afficher(int a){
        if(a == 0){
            cout <<"L'address: "<< address<<endl;
        }else if(a == 1){
            cout <<"Le numero: "<< number<<endl;
        }else{
            cout<< "Votre choix n'exist pas "<< endl;
        }
    }

private:
     string name;
     string address;
     string number;
};
class Majuscule{
public :void operator()(std::string& namee){
        for (char &c: namee)c = toupper(c);
    }
};
class Voyelle{

public:
    void operator()(std::string& name)const {
        char n[] = "*";

        for(char & i : name){
            switch(i){
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'y':
                    i = n[0];
                default:
                    break;
            }
        }
    }
};


int main() {
    auto *P1 = new Personne("Mohamed","Agadir","0614");
    auto *P2 = new Personne("Nour","Agadir","0614");
    auto *P3 = new Personne("Yes","Agadir","0614");
    unordered_multimap<string,Personne*> ListP(
            {
                    {P1->get_name(),P1},
                    {P2->get_name(),P2},
                    {P3->get_name(),P3}
            });

    auto it = ListP.find("Hassan");
    if(it != ListP.end()){
        it->second->afficher(1);
    }else{
        cout << "Le nom n'exist pas" <<endl;
    }
    /*std::list<std::string> items;
    std::string input;
    while(std::cin >> input && input != "exit") {
        items.push_back(input);
    }
    std::transform(items.begin(), items.end(),std::ostream_iterator<std::string>(std::cout, "\n"),Majuscule());
    std::transform(items.begin(), items.end(),std::ostream_iterator<std::string>(std::cout, "\n"),Voyelle());
*/
    return 0;
}


