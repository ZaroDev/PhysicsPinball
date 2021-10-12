#pragma once

// down-left thing
int staticBody01[18] = {
	65, 810,
	45, 828,
	46, 895,
	56, 903,
	146, 930,
	162, 932,
	171, 917,
	169, 907,
	85, 823
};

int ofset = 512 - 44;
// down-right thing
int staticBody02[18] = {
	ofset - 65, 810,
	ofset - 45, 828,
	ofset - 46, 895,
	ofset - 56, 903,
	ofset - 146, 930,
	ofset - 162, 932,
	ofset - 171, 917,
	ofset - 169, 907,
	ofset - 85, 823
};

// central thing
int staticBody03[70] = {
	237, 542,
	230, 540,
	226, 534,
	226, 510,
	231, 500,
	221, 486,
	219, 476,
	218, 450,
	215, 443,
	208, 441,
	201, 445,
	199, 451,
	199, 553,
	201, 562,
	205, 571,
	212, 579,
	222, 585,
	229, 587,
	236, 588,
	245, 588,
	256, 584,
	264, 577,
	271, 568,
	275, 556,
	275, 448,
	271, 443,
	265, 441,
	260, 444,
	256, 450,
	256, 475,
	253, 485,
	242, 501,
	248, 508,
	248, 535,
	242, 541
};

// up-left
int staticBody04[52] = {
	60, 540,
	66, 544,
	74, 544,
	79, 539,
	81, 526,
	85, 518,
	92, 511,
	101, 505,
	104, 501,
	103, 492,
	106, 480,
	114, 471,
	122, 467,
	126, 463,
	126, 455,
	124, 449,
	114, 438,
	99, 425,
	88, 419,
	78, 419,
	71, 423,
	65, 432,
	60, 452,
	57, 473,
	57, 528,
	58, 535
};

// up-left a little bit upper and left
int ofset02x = 58 - 24;
int ofset02y = 535 - 364;
int staticBody05[52] = {
	60 - ofset02x, 540 - ofset02y,
	66 - ofset02x, 544 - ofset02y,
	74 - ofset02x, 544 - ofset02y,
	79 - ofset02x, 539 - ofset02y,
	81 - ofset02x, 526 - ofset02y,
	85 - ofset02x, 518 - ofset02y,
	92 - ofset02x, 511 - ofset02y,
	101 - ofset02x, 505 - ofset02y,
	104 - ofset02x, 501 - ofset02y,
	103 - ofset02x, 492 - ofset02y,
	106 - ofset02x, 480 - ofset02y,
	114 - ofset02x, 471 - ofset02y,
	122 - ofset02x, 467 - ofset02y,
	126 - ofset02x, 463 - ofset02y,
	126 - ofset02x, 455 - ofset02y,
	124 - ofset02x, 449 - ofset02y,
	114 - ofset02x, 438 - ofset02y,
	99 - ofset02x, 425 - ofset02y,
	88 - ofset02x, 419 - ofset02y,
	78 - ofset02x, 419 - ofset02y,
	71 - ofset02x, 423 - ofset02y,
	65 - ofset02x, 432 - ofset02y,
	60 - ofset02x, 452 - ofset02y,
	57 - ofset02x, 473 - ofset02y,
	57 - ofset02x, 528 - ofset02y,
	58 - ofset02x, 535 - ofset02y
};

// up-right			offset=512-(512-58-418)
int ofset03 = 512 - 36-1;
int staticBody06[52] = {
	ofset03 - 60, 540,
	ofset03 - 66, 544,
	ofset03 - 74, 544,
	ofset03 - 79, 539,
	ofset03 - 81, 526,
	ofset03 - 85, 518,
	ofset03 - 92, 511,
	ofset03 - 101, 505,
	ofset03 - 104, 501,
	ofset03 - 103, 492,
	ofset03 - 106, 480,
	ofset03 - 114, 471,
	ofset03 - 122, 467,
	ofset03 - 126, 463,
	ofset03 - 126, 455,
	ofset03 - 124, 449,
	ofset03 - 114, 438,
	ofset03 - 99, 425,
	ofset03 - 88, 419,
	ofset03 - 78, 419,
	ofset03 - 71, 423,
	ofset03 - 65, 432,
	ofset03 - 60, 452,
	ofset03 - 57, 473,
	ofset03 - 57, 528,
	ofset03 - 58, 535
};

// more up-right
int staticBody07[52] = {
	ofset02x + ofset03 - 60, 540 - ofset02y,
	ofset02x + ofset03 - 66, 544 - ofset02y,
	ofset02x + ofset03 - 74, 544 - ofset02y,
	ofset02x + ofset03 - 79, 539 - ofset02y,
	ofset02x + ofset03 - 81, 526 - ofset02y,
	ofset02x + ofset03 - 85, 518 - ofset02y,
	ofset02x + ofset03 - 92, 511 - ofset02y,
	ofset02x + ofset03 - 101, 505 - ofset02y,
	ofset02x + ofset03 - 104, 501 - ofset02y,
	ofset02x + ofset03 - 103, 492 - ofset02y,
	ofset02x + ofset03 - 106, 480 - ofset02y,
	ofset02x + ofset03 - 114, 471 - ofset02y,
	ofset02x + ofset03 - 122, 467 - ofset02y,
	ofset02x + ofset03 - 126, 463 - ofset02y,
	ofset02x + ofset03 - 126, 455 - ofset02y,
	ofset02x + ofset03 - 124, 449 - ofset02y,
	ofset02x + ofset03 - 114, 438 - ofset02y,
	ofset02x + ofset03 - 99, 425 - ofset02y,
	ofset02x + ofset03 - 88, 419 - ofset02y,
	ofset02x + ofset03 - 78, 419 - ofset02y,
	ofset02x + ofset03 - 71, 423 - ofset02y,
	ofset02x + ofset03 - 65, 432 - ofset02y,
	ofset02x + ofset03 - 60, 452 - ofset02y,
	ofset02x + ofset03 - 57, 473 - ofset02y,
	ofset02x + ofset03 - 57, 528 - ofset02y,
	ofset02x + ofset03 - 58, 535 - ofset02y
};

// left border
int leftBorder[24] = {
	213, 1022,
	212, 1016,
	208, 1004,
	199, 995,
	52, 940,
	33, 930,
	25, 922,
	21, 913,
	18, 898,
	18, 282,
	3, 282,
	4, 1021
};

// midle border
int midleBorder[58] = {
	261, 1022,
	263, 1011,
	269, 1000,
	281, 992,
	412, 943,
	433, 934,
	443, 927,
	451, 917,
	456, 903,
	456, 349,
	458, 344,
	464, 342,
	469, 344,
	471, 349,
	471, 1023
};

int rightBorder[58] = {
	497, 1022,
	497, 336,
	492, 298,
	481, 262,
	464, 228,
	433, 188,
	400, 157,
	359, 131,
	331, 120,
	297, 111,
	266, 108,
	230, 108,
	186, 117,
	143, 134,
	98, 164,
	65, 198,
	48, 222,
	36, 222,
	42, 208,
	75, 164,
	125, 128,
	186, 100,
	273, 92,
	351, 112,
	406, 143,
	454, 187,
	492, 250,
	512, 332,
	511, 1022
};
