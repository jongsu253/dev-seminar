#ifndef __TRANSFER_H__
#define __TRANSFER_H__

typedef struct Transfer {
	char* (*get_user_name)(void);
	char* (*get_user_phone)(void);
	char* (*get_user_address)(void);
} Transfer;

Transfer* get_memory_transfer();
Transfer* get_file_transfer();

#endif /* __TRANSFER_H__ */

