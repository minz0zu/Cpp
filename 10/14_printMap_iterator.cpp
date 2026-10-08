#include <iostream>
#include <string>
#include <map>
using namespace std;
/* map iterator·Î ÀüÃ¼ Ãâ·Â
- map<K, V>::iterator it
- mapµµ begin(), end()¸¦ ÅëÇØ ÀüÃ¼ ¼øÈ¸ °¡´É
- it->first (Å°), it->second(°ª)
*/
void printMap(map<string, int>& m){
    for(map<string, int>::iterator it=m.begin(); it!=m.end(); it++){
        cout << it->first << ":" << it->second << "won\n";
    }
}
int main(){
    map<string, int> priceMap;
    priceMap["ºØ¾î»§"] = 2000;
    priceMap["À×¾î»§"] = 2500;
    priceMap.insert(make_pair("±¹È­»§", 3000));

    printMap(priceMap);
    priceMap.erase("ºØ¾î»§");
    printMap(priceMap);
    return 0;
}