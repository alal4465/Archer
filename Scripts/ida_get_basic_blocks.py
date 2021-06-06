from idautils import *
from idaapi import *
from idc import *
import os
import struct

SCRIPTS_FOLDER = os.path.split(ARGV[0])[0]
ANALYZED_FILE_PATH = os.path.basename(ARGV[1])
COVERAGE_FILE_PATH = os.path.join(SCRIPTS_FOLDER, "Artifacts", ANALYZED_FILE_PATH + ".coverage.bin")


def main():
	autoWait()
	
	blocks = []
	[[blocks.append(block.startEA) for block in idaapi.FlowChart(idaapi.get_func(funcea)) if is_code(getFlags(block.startEA))] for funcea in Functions()]
	
	with open(COVERAGE_FILE_PATH, 'wb') as f:
		[f.write(struct.pack("<Q", block)) for block in blocks]
	
	exit()

if __name__ == '__main__':
	main()
