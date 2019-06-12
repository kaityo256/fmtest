#include "gs.h"
#include <fstream>
#include <iostream>

void dump(Formura_Navi &n) {
  char filename[256];
  static int index = 0;
  sprintf(filename, "data/%03d.dat", index);
  index++;
  std::cout << filename << std::endl;
  std::ofstream ofs(filename);
  for (int ix = 0; ix < n.total_grid_x; ix++) {
    for (int iy = 0; iy < n.total_grid_y; iy++) {
      int ix2 = (ix - n.offset_x + n.total_grid_x) % n.total_grid_x;
      int iy2 = (iy - n.offset_y + n.total_grid_y) % n.total_grid_y;
      double v = formura_data.u[ix2][iy2];
      ofs << ix << " ";
      ofs << iy << " ";
      ofs << v << std::endl;
    }
    ofs << std::endl;
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
