//for this issignement i lerned a lot from: https://openclassrooms.com/fr/courses/7137751-programmez-en-oriente-objet-avec-c/7532446-utilisez-les-iterateurs-et-les-foncteurs
//and i had some issue inthe end with little thing that blocked my code... so i ask for a freind from my work to help me and he fixed the iissues.


//for my main i based on demo file.


#include "sources/OrgChart.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
using namespace ariel;

int main() {
    OrgChart organization;
    organization.add_root("SABA")               // Now SABA is the root                                     
        .add_sub("SABA", "SAVTA")               // Now the SAVTA is subordinate to SABA                   
        .add_root("SABA-RABA")                  // Now SABA-RABA is the root
        .add_sub("SABA-RABA", "SAVTA-RABA")     // Now the SAVTA-RABA is subordinate to SABA-RABA
        .add_sub("SABA-RABA", "SABA")           // Now the SABA is subordinate to SABA-RABA
        .add_sub("SAVTA", "ABA")                // Now the ABA  is subordinate to SAVTA
        .add_sub("SAVTA", "IMA")                // Now the IMA is subordinate to SAVTA
        .add_sub("SAVTA-RABA", "SAVTA2")         // Now the SAVTA2 is subordinate to SAVTA-RABA
        .add_sub("SABA", "ONCLE");               //Now the ONCLE is subordinate to SABA

  cout << organization << endl; 

    cout << "level order: " << endl;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
        cout << (*it) << " " ;
    } // should print: SABA-RABA SAVTA SAVTA-RABA SABA ABA IMA SAVTA2 ONCLE
     std::cout << std::endl;

    cout << "reverse level order: " << endl;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
        cout << (*it) << " " ;
    } // should print: ABA IMA SAVTA2 ONCLE SAVTA SAVTA-RABA SABA SABA-RABA
    std::cout << std::endl;

    cout << "preorder: " << endl;
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        cout << (*it) << " " ;
    }  // should print: SABA-RABA SAVTA ABA IMA SAVTA-RABA SAVTA2 SABA ONCLE
    std::cout << std::endl;

    cout << "level order: " << endl;
    for (auto element : organization) { // this should work like level order
        cout << element << " " ;
    } // should print: SABA-RABA SAVTA SAVTA-RABA SABA ABA IMA SAVTA2 ONCLE
    std::cout << std::endl;

    cout << "level order sizes: " << endl;
    // demonstrate the arrow operator:
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
        cout << it->size() << " " ;
    } // should print: 9 5 10 4 3 3 6 5
    std::cout << std::endl;
}