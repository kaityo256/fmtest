#include "gs.h"
#include <fstream>
#include <iostream>

void dump(Formura_Navi &n) {
  const int size = n.upper_x - n.lower_x;
  char filename[256];
  static int index = 0;
  sprintf(filename, "data/%03d.dat", index);
  index++;
  std::cout << filename << std::endl;
  std::ofstream ofs(filename);
  for (int i = 0; i < size; i++) {
    int i2 = (i - n.offset_x) % size;
    double v = formura_data.u[i2];
    ofs << i << " ";
    ofs << v << std::endl;
  }
}

int main(int argc, char **argv) {
  Formura_Navi n;
  Formura_Init(&argc, &argv, &n);
  for (int i = 0; i < 100; i++) {
    Formura_Forward(&n);
    dump(n);
  }
  Formura_Finalize();
}
