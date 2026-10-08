#include <iostream>
#include <string>
#include <map>
using namespace std;
/* map으로 만든 영한사전
----------------------
1. map 기본
- map<K, V>는 key와 value를 한 쌍으로 저장하는 컨테이너
- map 원소는 pair 구조이며, (key, value) 형태
- key는 중복될 수 없고, key 기준으로 자동 정렬
- 배열처럼 숫자인덱스로 위치를 찾는 것이 아니라, "이름표 역할의 key"로 값을 찾는다.
- 'map<string, string>'이면 key와 value가 모두 string
2. map에서 자주보는 기본 문법
- 'dic[key] = value' : 삽입 또는 수정
- 'dic.insert(make_pair(a, b))' 위와 둘 중에 하나의 방식으로 삽입을 한다.
- 'dic.find(key)' : key가 있으면 iterator, 없으면 end()
- 'dic.size()' : 저장된 key-value 쌍의 개수
- 'dic.begin()',  'dic.end()' : 전체 원소 순회 범위
*/
int main(){
    map<string, string> dic;

    // (영어, 뜻) 한쌍을 만들어 map에 저장
    dic.insert(make_pair("love", "사랑"));
    dic.insert(make_pair("apple", "사과"));
    // []는 pair 직접 만들지 않고, 삽입/수정 간단히 표현가능
    dic["cherry"] = "체리";

    cout << "The number of stored words: " << dic.size() << "\n";

    // iterator로 map 전체를 순회하여 출력**************************
    cout << "[dic list]\n";
    for(map<string, string>::iterator it = dic.begin(); it != dic.end(); it++){
        cout << " : " << it->second << "\n";
    }

      
    string eng;
    while(true){
        cout << "word search: ";
        getline(cin, eng);
        if(eng == "exit")
            break;
        if(dic.find(eng)==dic.end())
            cout << "NONE\n";
        else
         cout << dic[eng] << "\n";
    }
    cout << "Exit\n";
    return 0;
}