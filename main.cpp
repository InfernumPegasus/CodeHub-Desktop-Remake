#include "vcs/VCSApplication.h"

int main(int argc, char* argv[]) {
  codehub::VCSApplication application(argc, argv);
  application.Init();
  application.Run();

  return 0;
}