#include <stdio.h>
  
#include "transfer.h"
#include "guard.h"

int main(int argc, char* argv[]) {
	init_guard();

    Transfer* transfer = get_file_transfer();

    printf("------User Info-----\n");
    printf("Name : %s\n", transfer->get_user_name());
    printf("PHONE : %s\n", transfer->get_user_phone());
    printf("ADDRESS : %s\n", transfer->get_user_address());
}
