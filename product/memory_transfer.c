#include "transfer.h"
  
static char* get_name() {
    return "Buzzvil";
}

static char* get_phone() {
    return "010-XXXX-XXXX";
}

static char* get_address() {
    return "Daerim";
}

const static Transfer transfer = {
    .get_user_name = get_name,
    .get_user_phone = get_phone,
    .get_user_address = get_address
};

Transfer* get_memory_transfer() {
    return &transfer;
}
