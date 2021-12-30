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
    string name;
    int choix,choix_fin;
    unordered_multimap<string,Personne*> ListP{};

    do{
        cout << "************************"<<endl;
        cout << "1-Ajouter nouveau" << endl;
        cout<<"2-Chercher quelqu'un"<<endl;
        cout << "************************"<<endl;
        cin>>choix_fin;
        switch(choix_fin){
            case 1:{
                string address,number;
                cout << "Entrer votre nom: ";
                cin>>name;
                cout << "Entrer votre Address: ";
                cin>>address;
                cout << "Entrer votre number: ";
                cin>>number;
                if(name.empty() || address.empty() || number.empty()){
                    cout << "Les champs doivent etre tous remplis" <<endl;
                }else{
                    pair<string,Personne*> neww(name,new Personne(name,address,number));
                    ListP.insert(neww);
                    cout << "Welcome " << name << endl;
                }
                break;
            }
            case 2:{
                cout << "Le nom a chercher ?:";
                cin>>name;
                auto it = ListP.find(name);
                if(it != ListP.end()){
                    int i;
                    cout << "1-Son numero"<<endl;
                    cout << "2-Son address"<<endl;
                    cin>>i;
                    if(i==2||i==1){
                        it->second->afficher(i);
                    }else{
                        cout << "Invalid choix"<<endl;
                    }
                }else{
                    cout << "Le nom n'exist pas" <<endl;
                }
                break;
            }
            default:cout << "Choix invalid"<<endl;


        }
        cout << "Voulez vous exit : [0] si oui";
        cin>>choix;
    }while(choix != 0);*
    ListP.clear();
    cout << "Au revoir"<<endl;


    /**************************************/
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


