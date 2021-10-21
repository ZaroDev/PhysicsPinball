#pragma once

// down-left thing
int staticBody01[18] = {
	65, 710,
	45, 728,
	46, 795,
	56, 803,
	146, 830,
	162, 832,
	171, 817,
	169, 807,
	85, 723
};

int ofset = 512 - 44;
int offsetY = 100;
// down-right thing
int staticBody02[18] = {
	ofset - 65, 710,
	ofset - 45, 728,
	ofset - 46, 795,
	ofset - 56, 803,
	ofset - 146, 830,
	ofset - 162, 832,
	ofset - 171, 817,
	ofset - 169, 807,
	ofset - 85, 723
};

// central thing
int staticBody03[70] = {
	237, 542+40,
	230, 540+40,
	226, 534+40,
	226, 510+40,
	231, 500+40,
	221, 486+40,
	219, 476+40,
	218, 450+40,
	215, 443+40,
	208, 441+40,
	201, 445+40,
	199, 451+40,
	199, 553+40,
	201, 562+40,
	205, 571+40,
	212, 579+40,
	222, 585+40,
	229, 587+40,
	236, 588+40,
	245, 588+40,
	256, 584+40,
	264, 577+40,
	271, 568+40,
	275, 556+40,
	275, 448+40,
	271, 443+40,
	265, 441+40,
	260, 444+40,
	256, 450+40,
	256, 475+40,
	253, 485+40,
	242, 501+40,
	248, 508+40,
	248, 535+40,
	242, 541+40
};

// up-left
int staticBody04[52] = {
	60, 440,
	66, 444,
	74, 444,
	79, 439,
	81, 426,
	85, 418,
	92, 411,
	101, 405,
	104, 401,
	103, 392,
	106, 380,
	114, 371,
	122, 367,
	126, 363,
	126, 355,
	124, 349,
	114, 338,
	99, 325,
	88, 319,
	78, 319,
	71, 323,
	65, 332,
	60, 352,
	57, 373,
	57, 428,
	58, 435
};

// up-left a little bit upper and left
int ofset02x = 58 - 24;
int ofset02y = 535 - 364 - 100;
int staticBody05[52] = {
	60 - ofset02x, 540 - ofset02y- 2*offsetY,
	66 - ofset02x, 544 - ofset02y- 2*offsetY,
	74 - ofset02x, 544 - ofset02y- 2*offsetY,
	79 - ofset02x, 539 - ofset02y- 2*offsetY,
	81 - ofset02x, 526 - ofset02y- 2*offsetY,
	85 - ofset02x, 518 - ofset02y- 2*offsetY,
	92 - ofset02x, 511 - ofset02y- 2*offsetY,
	101 - ofset02x, 505 - ofset02y- 2*offsetY,
	104 - ofset02x, 501 - ofset02y- 2*offsetY,
	103 - ofset02x, 492 - ofset02y- 2*offsetY,
	106 - ofset02x, 480 - ofset02y- 2*offsetY,
	114 - ofset02x, 471 - ofset02y- 2*offsetY,
	122 - ofset02x, 467 - ofset02y- 2*offsetY,
	126 - ofset02x, 463 - ofset02y- 2*offsetY,
	126 - ofset02x, 455 - ofset02y- 2*offsetY,
	124 - ofset02x, 449 - ofset02y- 2*offsetY,
	114 - ofset02x, 438 - ofset02y- 2*offsetY,
	99 - ofset02x, 425 - ofset02y - 2*offsetY,
	88 - ofset02x, 419 - ofset02y - 2*offsetY,
	78 - ofset02x, 419 - ofset02y - 2*offsetY,
	71 - ofset02x, 423 - ofset02y - 2*offsetY,
	65 - ofset02x, 432 - ofset02y - 2*offsetY,
	60 - ofset02x, 452 - ofset02y - 2*offsetY,
	57 - ofset02x, 473 - ofset02y - 2*offsetY,
	57 - ofset02x, 528 - ofset02y - 2*offsetY,
	58 - ofset02x, 535 - ofset02y - 2*offsetY
};

// up-right			offset=512-(512-58-418)
int ofset03 = 512 - 36-1;
int staticBody06[52] = {
	ofset03 - 60, 540 - offsetY,
	ofset03 - 66, 544 - offsetY,
	ofset03 - 74, 544 - offsetY,
	ofset03 - 79, 539 - offsetY,
	ofset03 - 81, 526 - offsetY,
	ofset03 - 85, 518 - offsetY,
	ofset03 - 92, 511 - offsetY,
	ofset03 - 101, 505- offsetY,
	ofset03 - 104, 501- offsetY,
	ofset03 - 103, 492- offsetY,
	ofset03 - 106, 480- offsetY,
	ofset03 - 114, 471- offsetY,
	ofset03 - 122, 467- offsetY,
	ofset03 - 126, 463- offsetY,
	ofset03 - 126, 455- offsetY,
	ofset03 - 124, 449- offsetY,
	ofset03 - 114, 438- offsetY,
	ofset03 - 99, 425 - offsetY,
	ofset03 - 88, 419 - offsetY,
	ofset03 - 78, 419 - offsetY,
	ofset03 - 71, 423 - offsetY,
	ofset03 - 65, 432 - offsetY,
	ofset03 - 60, 452 - offsetY,
	ofset03 - 57, 473 - offsetY,
	ofset03 - 57, 528 - offsetY,
	ofset03 - 58, 535 - offsetY
};

// more up-right
int staticBody07[52] = {
	ofset02x + ofset03 - 60, 540 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 66, 544 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 74, 544 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 79, 539 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 81, 526 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 85, 518 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 92, 511 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 101, 505 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 104, 501 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 103, 492 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 106, 480 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 114, 471 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 122, 467 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 126, 463 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 126, 455 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 124, 449 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 114, 438 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 99, 425 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 88, 419 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 78, 419 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 71, 423 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 65, 432 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 60, 452 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 57, 473 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 57, 528 - ofset02y - 2*offsetY,
	ofset02x + ofset03 - 58, 535 - ofset02y - 2*offsetY
};

// left border
int leftBorder[24] = {
	213, 1022 - offsetY,
	212, 1016 - offsetY,
	208, 1004 - offsetY,
	199, 995- offsetY,
	52, 940 - offsetY,
	33, 930 - offsetY,
	25, 922 - offsetY,
	21, 913 - offsetY,
	18, 898 - offsetY,
	18, 282 - offsetY,
	3, 282 - offsetY,
	4, 1021 - offsetY
};

// midle border
int midleBorder[58] = {
	261, 1022 - offsetY,
	263, 1011 - offsetY,
	269, 1000 - offsetY,
	281, 992 - offsetY,
	412, 943 - offsetY,
	433, 934 - offsetY,
	443, 927 - offsetY,
	451, 917 - offsetY,
	456, 903 - offsetY,
	456, 349 - offsetY,
	458, 344 - offsetY,
	464, 342 - offsetY,
	469, 344 - offsetY,
	471, 349 - offsetY,
	471, 1023 - offsetY
};

int rightBorder[58] = {
	497, 1022 - offsetY,
	497, 336- offsetY,
	492, 298- offsetY,
	481, 262- offsetY,
	464, 228- offsetY,
	433, 188- offsetY,
	400, 157- offsetY,
	359, 131- offsetY,
	331, 120- offsetY,
	297, 111- offsetY,
	266, 108- offsetY,
	230, 108- offsetY,
	186, 117- offsetY,
	143, 134- offsetY,
	98, 164- offsetY,
	65, 198- offsetY,
	48, 222- offsetY,
	36, 222- offsetY,
	42, 208- offsetY,
	75, 164- offsetY,
	125, 128- offsetY,
	186, 100- offsetY,
	273, 92 - offsetY,
	351, 112- offsetY,
	406, 143- offsetY,
	454, 187- offsetY,
	492, 250- offsetY,
	512, 332- offsetY,
	511, 1022 - offsetY
};
