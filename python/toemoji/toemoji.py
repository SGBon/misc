# turn alphanumeric strings into emoji strings for use in making
# quality post on discord. only works on latin alphabet characters,
# the other languages aren't supported on discord.
# Can pipe input or redirect input in UNIX or specify files in command
# line to emojify

nummap=dict({
	"0":":zero:",
	"1":":one:",
	"2":":two:",
	"3":":three:",
	"4":":four:",
	"5":":five:",
	"6":":six:",
	"7":":seven:",
	"8":":eight:",
	"9":":nine:"
})

def line_to_emoji(line):
	outstr = ""
	for i in line.lower():
		if i == " ":
			outstr+="    "
		elif i.isdigit():
			outstr+=("%s " % nummap.get(i))
		elif i == "\n":
			pass
		else:
			outstr+=(":regional_indicator_%s: " % i)
	return outstr

import fileinput
if __name__ == "__main__":
	out = ""
	for line in fileinput.input():
		out+=line_to_emoji(line)

	print out
