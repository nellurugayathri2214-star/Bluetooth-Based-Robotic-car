#define LCD_D 0xf0
#define RS 1<<2
#define E 1<<3

void LCD_init(void);
void LCD_command(unsigned char);
void LCD_data(unsigned char);
void LCD_str(char*);
