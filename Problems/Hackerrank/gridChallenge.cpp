/*********************************************************************************************/
/* Problem: Grid Challenge (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a square grid of characters in the range ascii[a-z], rearrange elements of each row
  alphabetically, ascending. Determine if the columns are also in ascending alphabetical order,
  top to bottom. Return YES if they are or NO if they are not.  Only elements within the same
  row can be rearranged. They cannot be moved to a different row.

  > Example:
      grid = ["abc","ade","efg"]
          a b c
          a d e     --->    rows and columns are in alphabetical order, return "YES".
          e f g

--Inputs:
    - string grid[n]: an array of strings

--Outputs:
    - string: either YES or NO

--Reasoning:
  Simply go over the grid sorting each string and after they're sorted check the strings formed by
  the columns and see if they are sorted. If so, it's possible to rearrange the elements, return
  "YES". Otherwise, return "NO".

--Time complexity: O((n^2)*log(n))

--Space complexity: O(1)


*/

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>

std::string gridChallenge(std::vector<std::string> grid)
{
  // order the strings:
  for (int i{0}; i < grid.size(); ++i)
  {
    std::sort(grid.at(i).begin(), grid.at(i).end());
  }

  // check if the cols are ordered, if they are not, return "NO":
  for (int col{0}; col < grid.at(0).size(); ++col)
  {
    for (int row{0}; row < grid.size() - 1; ++row)
    {
      if (grid.at(row).at(col) > grid.at(row + 1).at(col))
      {
        return "NO";
      }
    }
  }

  return "YES";
}

int main()
{
  std::cout << std::boolalpha;

  std::vector<std::string> strArr{"abc", "ade", "efg"};
  std::cout << "Rearrangement is possible: " << gridChallenge(strArr) << "\n"; // YES

  strArr = {"ebacd", "fghij", "olmkn", "trpqs", "xywuv"};
  std::cout << "Rearrangement is possible: " << gridChallenge(strArr) << "\n"; // YES

  strArr = {"abc", "lmp", "qrt"};
  std::cout << "Rearrangement is possible: " << gridChallenge(strArr) << "\n"; // YES

  strArr = {"mpxz", "abcd", "wlmf"};
  std::cout << "Rearrangement is possible: " << gridChallenge(strArr) << "\n"; // NO

  strArr = {"abc", "hjk", "mpq", "rtv"};
  std::cout << "Rearrangement is possible: " << gridChallenge(strArr) << "\n"; // YES

  strArr = {"vzzrxgrnvpyjotknhbkiiifbiuwcpvmfapjxntw", "pisviqkjniiwmyshjknxlpksbsdrhspmyvvduzs",
            "aobisvvwgybnimvybokglhspetkanqleddgedot", "rezemaxkxecxwimxaeczghyrnyjvolfxtsaafvw",
            "ndwpbvwjiqyrmxpvguzngmbbwjvetbzjnztgoon", "kjpzezwjlpmcduyuestpojisaqtuzogmkkpqwuv",
            "coboywgjbwdxzgcrydxvufuqmytavfvnangydcd", "vlupqopswxwcdniowxnqxclnafbytnokpsxlvdv",
            "osrxkmpxetcgvujgrssfdhnomxogwfjsyvabifv", "dusxcvzragkjrskllgrwnfmikyiwfslyzrvtqfa",
            "spxwiblilwbussklwfutvicmzkafkwjcfzqjkzh", "fkohggspbbfvudtqgjpjuvywzxsdwwmmknigfuk",
            "hkplzjrshzabtkjowvqxxiilujkkgbfmxexbebx", "wzkccnyjhaubiiilpktcwkpnxoxxiufypqeqqky",
            "sntrbgbdyitfnamzevypgaowqizgaedcdboqxaw", "xslgigeifaqqzvqjcnoqxqdovpfbszvmfrjhmqt",
            "kakeviomxlknqmocskoteeyrskvkkshezjllmyv", "pekogeckvoxrzmufdijhbdztktsavvzyrlaxpvn",
            "pfdeemegondceocgdeexavdbaruhtivxdxgvasx", "hdllduyljbjgjifowdecegdmwuuynznggoimtoh",
            "rjpbtxshbohnvrpuyogrriwapvjgupiumsinxry", "kzypvfegsllncdoldpbhyhxwnxkqokppnkltdgq",
            "cldnrmfywtadiuktaqyqudihncxlzeabveoetek", "ztzmrjqpgbrjildvjccaftrmdcgysegdtoojjwk",
            "bofksxvfhtcfhrgfsshpiwqrlqggbfqklllziky", "seyuhbroajuqjxqkyhqvlleqdwmfgsgebaxsvpq",
            "hltpxpuaxsibtkpoqialowvkdlkbyhakbefzgzn", "fvkyzegsdfawenripawinuvdlhvwwrleqwtygcs",
            "dugyunxtuzbgdnjpanaugtdvoemczinalxvtygl", "dyizgkfpbhhabdfrkepzruaiwgpgxtdfnendnhl",
            "feckqnckvsulwuvfoopnnyyhqdxmwxjrawkwxsv", "xqmnthpkodufmwzpoczvenzxehrdqqpzgnnqkdd",
            "qhmtpvgwnqeztvffmnrihwfqdsdkljvanccmsyg", "dwupgfksdevslhkdrcmytdpafyijgjbfssyouza",
            "endhjybrgxkbpglsfrvsqvbikfwcxnjtvyntofj", "ipyowznudnfjiqmpsivlwmauyexkrnsxntddcrs",
            "ygvaslfhmlxcggqsemzcuwhnrljejhwkshmuxmw", "ephqftahxlrjoclovgirvwdfclqtpubzpsllcsc",
            "nwdjeczlgdjeziimhkatazntvjcywwpefbjzjyw"};
  std::cout << "Rearrangement is possible: " << gridChallenge(strArr) << "\n"; // NO

  strArr = {"eibjbwsp", "ptfxehaq", "jxipvfga", "rkefiyub", "kalwfhfj", "lktajiaq", "srdgoros", "nflvjznh"};
  std::cout << "Rearrangement is possible: " << gridChallenge(strArr) << "\n"; // NO

  return 0;
}