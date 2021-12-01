/*********************************************************************************************/
/* Problem: Caesar Cipher (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Julius Caesar protected his confidential information by encrypting it using a cipher. Caesar's
  cipher shifts each letter by a number of letters. If the shift takes you past the end of the
  alphabet, just rotate back to the front of the alphabet. In the case of a rotation by 3, w, x,
  y and z would map to z, a, b and c.
    > Original alphabet:      abcdefghijklmnopqrstuvwxyz
    > Alphabet rotated +3:    defghijklmnopqrstuvwxyzabc

--Inputs:
    string s: cleartext
    int k: the alphabet rotation factor

--Output:
    string: the encrypted string

--Reasoning:
  Iterate over the input string using each character' ASCII code and the rotation factor to calculate
  the encrypted character. Since we know that lowercase characters go from 97 to 122 and uppercase
  characters from 65 to 90, it's just a matter of adding 'k' to the original value to get the new
  character' ASCII code. The challenge is to deal with large values of 'k' where we need to guarantee
  that once we get to the end of the sequence (i.e. once we get to 'z'), we rotate back to the front
  until we're finished. To do this, we check if:
      ASCII(original character) + k <= 90, for uppercase characters
      ASCII(original character) + k <= 122, for lowercase characters
  If so, it means we need to rotate back to the front (i.e. to 'a' or 'A'), so we perform the following
  calculation:
      (ASCII(original character) + k - 91)%26, for uppercase characters
      (ASCII(original character) + k - 123)%26, for lowercase characters
  The reason why we use 91 and 123 instead of 90 and 122, respectively, is to make sure that we're not
  skipping the first letter in the sequence. Additionaly, 26 is the number of letters in each sequence.
  The result of the modulus operation gives us the offset from the first character.

--Time complexity:
  O(L), where L is the length of the string, since we iterate over the entire string.

--Space complexity:
  O(L), since we return a same sized encrypted string.
*/

#include <iostream>
#include <string>
#include <iomanip>

std::string caesarCipher(const std::string &s, int k)
{
  std::string encrypted;

  for (auto &c : s)
  {
    char newChar = c;
    int asciiCode = int(c);

    if (asciiCode >= 65 && asciiCode <= 90)
    {
      newChar = ((newChar + k) <= 90) ? (newChar + k) : ('A' + ((newChar + k - 91) % 26));
    }
    else if (asciiCode >= 97 && asciiCode <= 122)
    {
      newChar = ((newChar + k) <= 122) ? (newChar + k) : ('a' + ((newChar + k - 123) % 26));
    }
    encrypted.push_back(newChar);
  }

  return encrypted;
}

int main()
{
  std::cout << std::boolalpha;

  std::string s{"www.abc.xy"};
  int k{87};
  std::string enc = caesarCipher(s, k);
  std::string expected{"fff.jkl.gh"};
  std::cout << "Original: " << s << "\n"
            << "Encrypted: " << enc << "\n"
            << "Expected: " << expected << "\n"
            << "Result: " << (enc == expected) << "\n\n";

  s = {"159357lcfd"};
  k = 98;
  enc = caesarCipher(s, k);
  expected = {"159357fwzx"};
  std::cout << "Original: " << s << "\n"
            << "Encrypted: " << enc << "\n"
            << "Expected: " << expected << "\n"
            << "Result: " << (enc == expected) << "\n\n";

  s = {"!m-rB`-oN!.W`cLAcVbN/CqSoolII!SImji.!w/`Xu`uZa1TWPRq`uRBtok`xPT`lL-zPTc.BSRIhu..-!.!tcl!-U"};
  k = 62;
  enc = caesarCipher(s, k);
  expected = {"!w-bL`-yX!.G`mVKmFlX/MaCyyvSS!CSwts.!g/`He`eJk1DGZBa`eBLdyu`hZD`vV-jZDm.LCBSre..-!.!dmv!-E"};
  std::cout << "Original: " << s << "\n"
            << "Encrypted: " << enc << "\n"
            << "Expected: " << expected << "\n"
            << "Result: " << (enc == expected) << "\n\n";

  s = {"Pz-/aI/J`EvfthGH"};
  k = 66;
  enc = caesarCipher(s, k);
  expected = {"Dn-/oW/X`SjthvUV"};
  std::cout << "Original: " << s << "\n"
            << "Encrypted: " << enc << "\n"
            << "Expected: " << expected << "\n"
            << "Result: " << (enc == expected) << "\n\n";

  s = {"6DWV95HzxTCHP85dvv3NY2crzt1aO8j6g2zSDvFUiJj6XWDlZvNNr"};
  k = 87;
  enc = caesarCipher(s, k);
  expected = {"6MFE95QigCLQY85mee3WH2laic1jX8s6p2iBMeODrSs6GFMuIeWWa"};
  std::cout << "Original: " << s << "\n"
            << "Encrypted: " << enc << "\n"
            << "Expected: " << expected << "\n"
            << "Result: " << (enc == expected) << "\n\n";

  return 0;
}