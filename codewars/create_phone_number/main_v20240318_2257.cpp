#include <string>


std::string createPhoneNumber(const int arr [10]) { 
  std::string out = "";
  for (int32_t i = 0; i < 10; ++i) {
    if (i == 0) { out = out + "("; }
    out = out + std::to_string(arr[i]);
    if (i == 2) { out = out + ") "; }
    if (i == 5) { out = out + "-"; }
  }
  return out;
}
