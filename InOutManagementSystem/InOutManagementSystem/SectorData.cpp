#include "SectorData.h"

//�R���X�g���N�^
SectorData::SectorData()
{
	//�Z�N�^�[���u���b�N���������J��Ԃ�
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//�e�u���b�N��16�o�C�g�̗̈�m��
		RWBlock[i] = new BYTE[BLOCK_BYTE];
		//�m�ۂ����������̏��������s��
		memset(RWBlock[i], 0x00, BLOCK_BYTE);
	}
	//�A�N�Z�X����̃u���b�N�ɂ�16�o�C�g�̗̈�m��
	acsessBlock = new BYTE[BLOCK_BYTE];
	//�m�ۂ����������̏�����
	memset(acsessBlock, 0x00, BLOCK_BYTE);
}

//�f�X�g���N�^
SectorData::~SectorData()
{
	//�Z�N�^�[���̃u���b�N���������J��Ԃ�
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//�e�u���b�N�̊m�ۂ��ꂽ�̈���������
		delete RWBlock[i];
	}
	//�A�N�Z�X����̃u���b�N���������
	delete acsessBlock;
}

SectorData& SectorData::operator=(SectorData& sector)
{
	//�ǂݏ����p�u���b�N�������J��Ԃ�
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//�e�u���b�N�̃����������̃u���b�N���̃o�C�g�����R�s�[����
		memcpy(this->RWBlock[i], sector.RWBlock[i], BLOCK_BYTE);
	}
	//�A�N�Z�X����̃u���b�N���o�C�g�����R�s�[����
	memcpy(this->acsessBlock, sector.acsessBlock, BLOCK_BYTE);

	//���g��Ԃ�
	return *this;
}
