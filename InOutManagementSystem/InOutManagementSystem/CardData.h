#pragma once

#include <vector>
#include "SectorData.h"

class CardData {
public:
	//�Z�N�^�[���Ƃ̃f�[�^�̔z��
	std::vector<SectorData*> sector;
	
public:
	//�R���X�g���N�^
	CardData(int sectorN) {
		//�����̐��̃Z�N�^�z���
		sector = std::vector<SectorData*>(sectorN);
		//�������J��Ԃ�
		for (int i = 0; i < sectorN; i++) {
			//�Z�N�^���Ƃɍ쐬����
			sector[i] = new SectorData();
		}
	}
	//�f�X�g���N�^
	~CardData() {
		//�Z�N�^�̐��������J��Ԃ�
		for (int i = 0; i < sector.size(); i++) {
			//�Z�N�^��j������
			//delete sector[i];
		}
	}
};