run:
	python main.py

exe:
	@pyinstaller --onefile main.py -n Explicits
	@./dist/Explicits.exe
