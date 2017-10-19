#pragma once

#include <windows.h>

//�Z�N�^�[���̃u���b�N��
#define SECTOR_BLOCK_NUM (3)
//�u���b�N���̃o�C�g��
#define BLOCK_BYTE (16)

//�Z�N�^�[��̃f�[�^��ێ����Ă������߂̃N���X
class SectorData {
public:
	//�ǂݏ����Ɏg�p����u���b�N(�Z�N�^�[���ɂ�3��)
	BYTE* RWBlock[SECTOR_BLOCK_NUM];
	//�A�N�Z�X������s���u���b�N(�Z�N�^�[����4�ڂ̃u���b�N)
	BYTE* acsessBlock;

public:
	SectorData();
	~SectorData();

	//������Z�q
	SectorData& operator=(SectorData& sector);
};