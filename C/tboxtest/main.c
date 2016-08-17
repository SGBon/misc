#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <termbox.h>

void show_string(const char* str, int x, int y);
void scroll_down(void);

int main(){
	if(tb_init() < 0)
		return -1;

	struct tb_cell cell;
	cell.ch = 'a';
	cell.fg = TB_GREEN;
	cell.bg = TB_DEFAULT;

	tb_put_cell(0,0,&cell);
	tb_present();

	sleep(1);

	for(size_t i = 0;i<6;i++){
		show_string("hello",0,i);
	}

	sleep(1);

	scroll_down();

	sleep(1);

	tb_shutdown();
}

void show_string(const char* str,int x, int y){
	for(size_t i = x;i<strlen(str);i++){
		tb_change_cell(i,y,str[i],TB_GREEN,TB_DEFAULT);
	}
	tb_present();
}

void scroll_down(){
	struct tb_cell* cells = tb_cell_buffer();
	int w = tb_width();
	int h = tb_height();

	for(int i = 0;i<h-1;i++){
		for(int j = 0;j<w;j++){
			struct tb_cell* currcell = &cells[i*w + j];
			struct tb_cell* undercell = &cells[(i+1)*w + j];
			memcpy(currcell,undercell,sizeof(struct tb_cell));
			memset(undercell,'\0',sizeof(struct tb_cell));
		}
	}
	tb_present();
}
