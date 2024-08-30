#include "stdafx.h"
#include <sstream> 
#include <iostream> 
#include <fstream> 
#include <istream>
#include <vector>
#include <algorithm>
#include "write.h"
#include "read.h"
#include "matrix.h"
#include "equate.h"
using namespace std;

int main(){
	write* clutteredScene = new write(1024, 768,"Cluttered_scene.txt");
	read* wallyGrey = new read(36, 49,"Wally_grey.txt");
	cout << "Starting...It Will Take A Moment!" << endl;

	int maxPixels = -1;
	int maxPosX, maxPosY;
	int user = 5;

	std::vector<equate>Compare;

	for (int i = 0; i < clutteredScene->w - wallyGrey->w; i += 2){ //i = 162 & j = 144 doesn't produce error, all others do
		for (int j = 0; j < clutteredScene->h - wallyGrey->h; j += 2){
			double correctPix = 0;
			for (int x = 0; x < wallyGrey->w; x++){
				for (int y = 0; y < wallyGrey->h; y++){
					//cout << i << endl;
					double w = clutteredScene->Matrix->getValue(i + x, j + y);
					double q = wallyGrey->Matrix->getValue(x, y);
					if (q < 255.0) {
						correctPix = correctPix + ((w - q) * (w - q));
					}
					//if (clutteredScene[(j * 1024) + i] == wallyGrey[(y * 36) + x] && wallyGrey[(y * 36) + x] != 255){
						//correctPix++;
					//}
				}
				
			}
			equate temp = equate(i, j, correctPix);
			Compare.push_back(temp);

			if (Compare.size() > user){
				std::sort(Compare.begin(), Compare.end());
				Compare.pop_back();
			}

			/*if (correctPix > maxPixels){
				maxPixels = correctPix;
				maxPosX = 162; //i/2;
				maxPosY = 144; //j/10*1.9;
			}*/
		}
	}
	for (int x = 0; x < user; x++)
	{
		for (int i = 0; i < 36; i++) {
			for (int j = 0; j < 49; j++) {
				if (i == 0 || i == (36 - 1) || j == 0 || j == (49 - 1)) {
					clutteredScene->Matrix->setValue(i + Compare[x].xCompare, j + Compare[x].yCompare, 0.0);
					//clutteredScene[((j + maxPosY) * 1024) + (i + maxPosX)] = 0;
				}
			}
		}
	}
	clutteredScene->write_pgm("Wally_restored.pgm");
	cout << "Complete!" << endl;
	system("pause");
	return 0;
}

