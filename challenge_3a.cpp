// challenge_3a.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>


using namespace std;
unordered_map <std::string, string> valid_words = {};
unordered_map <std::string, string> pattern_input = {};

//string final_map = "Z o;J w;L e;T i;D r;V k;Y n;M g;C q;P a;H u;B d;I v;W l;R b;K x;A p;F s;X m;G t;O c;S h;N y;E f;Q z;";
//string challenge_3a = "CSTW, T BX SABETYI HZ GMAEAY HZ GCABV MTHS WTGA XATHYAF. GSA MBG CBFH ZL HSA HABX MSZ GCWTH HSA BHZX BYE HZIAHSAF MTHS LFTGRS SBG MZFVAE ZJH HSA EAHBTWG ZL SZM TH MZFVG. GSA TG B OFTWWTBYH RSAXTGH BG MAWW BG B CSPGTRTGH BYE T BX SZCTYI GSA RBY GSAE GZXA WTISH ZY SZM WTVAWP TH TG HSBH HSBH ETA BWRSAXTGHAY RZJWE EAKAWZC B YJRWABF CZMAF IAYAFBHTZY GPGHAX LFZX HSA CFZRAGG.        ZY HSA MBP OBRV, T CWBY HZ BWGZ KTGTH GZXA CAZCWA T VYZM TY YZFMBP.B YAM CZMAF GZJFRA MTWW OA ZL YZ JGA HZ HSA YBQTG MTHSZJH HSA FBM XBHAFTBWG LZF XBYJLBRHJFTYI, BYE B WZH ZL HSA XBUZF OBJNTHA GXAWHAFG TY AJFZCA BFA OBGAE TY HSA RZJYHFP.AKAY MTHSZJH B YAM GZJFRA ZL CZMAF HSA IAFXBY XTWTHBFP CWBYYAFG MTWW SBKA HSATF APA ZY GJCCWP WTYAG BYE HSA YZFMAITBY BWJXTYTJX RZXCBYTAG XJGH OA ZYA ZL HSATF CFTXA HBFIAHG.T HSZJISH T MZJWE EFZC TY BYE HFP HZ IAH B GAYGA ZL SZM MAWW EALAYEAE HSAGA CWBRAG BFA.HSAFA XBP BWFABEP SBKA OAAY BCCFZBRSAG LFZX IAFXBYP BG CBFH ZL HSATF BFXG OJTWE - JC BYE TH MZJWE OA IZZE HZ VYZM HSBH HZZ.TL HSA MZFGH SBCCAYG BYE YZFMBP TG TYKBEAE, HSAY T MBYH HZ SBKA GZXA BIAYHG BWFABEP AXOAEEAE TY HSA YBHTZYBW TYLFBGHFJRHJFA BYE MA YAAE HZ HSTYV BOZJH SZM MA MZJWE GARJFA RZXXJYTRBHTZYG TY BY ZRRJCTAE RZJYHFP.TL PZJ ZF HSA BIAYRP SBKA BYP RZYHBRHG HSAFA HSAY WAH XA VYZM.MTHS B WTHHWA WJRV T XBP AKAY IAH HZ GAA HSA YZFHSAFY WTISHG MSTWA T BX HSAFA.";
string challeng = "WSIJK BYYKSCT DW VSY HZARYBSJKYC ADBBSKKYY, IYSARJYIQSYRLCTJBSCSJKYISLB, KNYCKP CSCKR HFISZ CSCYKYYC KRSIKP CSCY"
"KRY ADBBSKKYY NHJ IYADCMYCYV EP KRY BSCSJKYI HK KRY IYGLYJK DW KRY ARHCAYZZDI RSBJYZW."
"SK SJ KHJXYV NSKR IYHZSJSCT KRY BSZSKHIP HCV SCVLJKISHZ FIDBSJY DW CLAZYHI YCYITP."
"KRY ADBBSKKYY IYADTCSJYJ KRY KYARCSAHZ ARHZZYCTYJ SCMDZMYV SC SCVLJKISHZSJSCT KRY FIDAYJJYJ RSKRYIKD ADCVLAKYV LCVYI ZHEDIHKDIP ADCVSKSDCJ, ELK WYYZJ KRHK KRY DEJKHAZYJ AHC EY DMYIADBY EP H ADBESCHKSDC DW JASYCKSWSA HCV YCTSCYYISCT YOAYZZYCAY HZIYHVP FDJJYJJYV EP KRY JKHKY."
"KRY ADBBSKKYY SVYCKSWSYV KRHK KRY FISCASFZY SJJLY SJ KRHK DW ADCKIDZZSCT KRY CLAZYHI IYHAKSDC NRSAR SJ BYVSHKYV EP KRY YCYITP DW WIYY CYLKIDCJ.KRYJY CYYV KD EY JZDNYV KD YWWYAKSMYZP RHICYJJ KRYSI FDNYI, HCV KD KRSJ YCV KRY ADBBSKKYY IYADBBYCVJ KRY HAGLSJSKSDC DW H JLSKHEZY BDVYIHKDI."
"KRY EYJK - XCDNC AHCVSVHKY SJ VYLKYISLB HCV KRY EYJK JDLIAY DW KRSJ BHKYISHZ SJ KRY FDNYI FZHCK HK MYBDIX SC CDINHP.KRY KIDCJKHV HCV EILC YZYAKIDZPKSA FIDAYJJ HK KRHK WHASZSKP SJ FIDVLASCT DMYI KNYCKP XSZDTIHBJ DW RYHMP NHKYI FYI PYHI, HCV KRSJ ADLZV YHJSZP EY JAHZYV LF."
"JSCAY NY VD CDK NHCK KD HZYIK DLI YCYBSYJ KD KRY SBFDIKHCAY DW KRY BHKYISHZ KRY ADBBSKKYY IYADBBYCVJ FZHASCT HC SCSKSHZ DIVYI WDI WSMY ZSKIYJ DW RYHMP NHKYI KRIDLTR DLI DNC VPY SCVLJKIP JPCVSAHKY ADIFDIHKSDC NRSAR, EP RHFFP HAASVYCK, DNCJ H GLHIKYI DW KRY JRHIYJ SC KRY MYBDIX FZHCK.";

string final_map = "A:e;B:a;C:p;E:d;F:r;G:s;H:t;I:g;J:u;K:v;L:f;M:w;O:b;P:y;Q:z;R:c;S:h;T:i;U:j;V:k;W:l;X:m;Y:n;Z:o;N x;";
unordered_map<char, char> init_map;
 

string create_pattern(const string& word) {
    string pattern = "";    
    unordered_map<char, int> map;
    int i = 0;
    for (const char& ch : word) {
        if (map.find(ch) == map.end()) {
            map[ch] = (i++) + 48;
        }
    }

    for (const char &ch : word) {
        pattern += map[ch];
    }
    return pattern;
}

int nchar(const string& word) {
    unordered_map<char, int> map;
    int output = 0;
    for (char ch : word) {
        if (map.find(ch) == map.end()) {
            map[ch] =  1;
            output++;
        }
    }
    return output;
}

bool compareLen(const std::string& a, const std::string& b)
{
    if (a.size() != b.size()) {
        return (a.size() < b.size());
    }
    return nchar(a) < nchar(b);
}


int score(string word) {
    if (init_map.size() < 8) {
        return 1000 - word.size();
    }

    int missing = 0;
    for (char ch : word) {
        if (init_map.find(ch) == init_map.end()) {
            missing++;
        }
    }
    if (missing == 0) {
        return 0;
    }

    return missing * 100 - word.size();
}



int cal_score(string word, const unordered_map<char, char> char_map) {
    if (char_map.size() < 8) {
        return 1000 - word.size();
    }

    int missing = 0;
    for (char ch : word) {
        if (char_map.find(ch) == char_map.end()) {
            missing++;
        }
    }
    if (missing == 0) {
        return 0;
    }

    return missing * 100 - word.size();
}

vector<string> break_into_words(const string& input) {

    string tmp = "";
    for (char ch : input) {
        if (ch >= 'A' && ch <= 'Z') {
            tmp += ch;
        }
        else {
            tmp += " ";
        }
    }

    unordered_map<string, int> unique_words;

    vector<string> words;
    istringstream ss(tmp);
    while (std::getline(ss, tmp, ' ')) {
        if (tmp.size() > 3 && score(tmp) > 0) {
            unique_words[tmp] = 1;
        }
    }

    for (auto e : unique_words) {
        words.push_back(e.first);
    }

    for (int i = 0; i != words.size(); ++i)
        for (int j = i + 1; j != words.size(); ++j)
            if (score(words[i]) > score(words[j])) {
                string tmp = words[i];
                words[i] = words[j];
                words[j] = tmp;
    }
    return words;
}


bool check_pattern(const string& original, const string& target, unordered_map<char, char> char_map) {
    if (valid_words[original] != pattern_input[target]) {
        return false;
    }

    for (int i = 0; i != original.size(); ++i) {
        char ch = target[i];
        if (char_map.find(ch) != char_map.end()) {
            if (char_map[ch] != original[i]) {
                return false;
            }
        }
    }
    return true;
}


bool possible(unordered_map<char, char> char_map, const std::vector<string>& words) {
    int count = 0;
    for (const string& word : words) {
        if (cal_score(word, char_map) == 0) {
            continue;
        }
        bool ok = false;
        for (auto e : valid_words) {
            if (check_pattern(e.first, word, char_map)) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            count++;
            if (count > 20) {
                return false;
            }
        }
    }
    return true;
}

bool check_valid(const string& original, const string& target, const unordered_map<char, char> &char_map) {
    unordered_map<char, char> mapped_char;

    for (const auto& e : char_map) {
        mapped_char[e.second] = 1;
    }

    for (int i = 0; i != original.size(); ++i) {
        if (char_map.find(target[i]) != char_map.end()) {
            if (char_map.at(target[i]) != original[i]) {
                return false;
            }
        }
        else {
            if (mapped_char.find(original[i]) != mapped_char.end()) {
                return false;
            }
        }
    
    }
    return true;
}


void print_map(unordered_map<char, char> char_map) {
    cout << "size:" << char_map.size() << "\n";
    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        if (char_map.find(ch) != char_map.end()) {
            cout << ch << ":" << char_map.at(ch) << ";";
        }
    }
    cout << "\n";
}

void scan_for_all(const std::vector<string>& words, int index, unordered_map<char, char> char_map, int max_value) {
    if (index >= words.size()) {
        return;
    }
    string word = words.at(index);

    int    count = 0;
    for (char ch : word) {
        if (char_map.find(ch) == char_map.end()) {
            count++;
        }
    }
    if (count == 0) {
        scan_for_all(words, index + 1, char_map, max_value);
        return;
    }
    
    for (auto e : valid_words) {
        if (check_pattern(e.first, word, char_map)) {
            if (!check_valid(e.first, word, char_map)) {
                continue;
            }
            
            unordered_map<char, char> new_char_map;
            for (int i = 0; i != word.size(); ++i) {
                new_char_map[word.at(i)] = e.first.at(i);
            }
            for (auto e : char_map) {
                new_char_map[e.first] = e.second;
            }
            cout << e.first << " " << word << "\n";
            cout << "checking possible...\n";
            if (possible(new_char_map, words)) {            
                
                if (new_char_map.size() > max_value) {
                    max_value = new_char_map.size();
                    print_map(new_char_map);
                }


                scan_for_all(words, index + 1, new_char_map, max_value);
            }
        }
    }
        scan_for_all(words, index + 1, char_map, max_value);
    

}

unordered_map<char, char> build_map(string map_string) {
    unordered_map<char, char> output;
    for (int i = 0; i + 2 < map_string.size(); i += 4) {
        output[map_string[i]] = map_string[i + 2];
    }
    return output;
}


string re_map(string input, unordered_map<char, char> char_map) {
    string output = "";
    for (char ch : input) {
        output += (char_map.find(ch) == char_map.end()) ? ch : char_map[ch];
    }
    return output;
}


void thin_dictionary(vector<string>& words) {

    unordered_map<string, string> patterns;
    for (auto word : words) {
        patterns[create_pattern(word)] = 1;
    }

    cout << "thinning dictionary...\n";
    unordered_map<string, string> new_dictionary;
    for (auto e : valid_words) {
        if (patterns.find(e.second) == patterns.end()){
            continue;
        }
        new_dictionary[e.first] = e.second;

        /*
        for (auto word : words) {
            if (check_pattern(e.first, word, init_map)) {
                new_dictionary[e.first] = e.second;                
                break;
            }
        }*/
    }

    valid_words.clear();
    for (auto e : new_dictionary) {
        valid_words[e.first] = e.second;
    }
    cout << "dictionary size = " << valid_words.size() << "\n";

}


int main(){

    init_map = build_map(final_map);
    ifstream file("c:\\decript\\dictionary.txt");

    string str;
    int nword = 0;
    cout << "loading dictionary..." << "\n";
    while (getline(file, str)) {        
        valid_words[str] = create_pattern(str);        
    }
    cout << "dictionary loaded.\n";
    
        
    
    
    vector<string> words = break_into_words(challeng);

    thin_dictionary(words);

    for (const string &word : words) {
        pattern_input[word] = create_pattern(word);
        cout << word << " " << score(word) << "\n";
     }

    cout << re_map(challeng, init_map) << "\n";
    scan_for_all(words, 0, init_map, 0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
