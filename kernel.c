//фукция, которая будет вызвана загрузчиком
void kmain(void)
{
	const char *str = "Hello,world!"; //строка, которую мы выведм на экран при запуске ОС
	char *vidptr = (char*)0xb8000; 	//видео пямять начинается здесь
	unsigned int i = 0;
	unsigned int j = 0;

	//данный цикл очистит экран от системной информации
	while(j < 80 * 25 * 2) {
		vidptr[j] = ' '; //пустой символ
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;

	// в этом цикле строка записывается в видеопамять
	while(str[j] != '\0') {
		//выводим нашу строку (str) на экран
		vidptr[i] = str[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}