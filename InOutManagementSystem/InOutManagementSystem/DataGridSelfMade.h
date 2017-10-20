#pragma once

#include "ChainData.h"
#include "Cell.h"

namespace narita {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;

	ref class DataGridSelfMade
	{
	private:
		PictureBox^ pictureBox;	//�`�悵�����̂�z�u����s�N�`���[�{�b�N�X
		Bitmap^ canvas;			//�`���̃I�u�W�F�N�g
		Graphics^ graphic;		//�`�悷�邽�߂̃I�u�W�F�N�g
		Pen^ cellFramePen;		//�Z���̘g���������߂̃y���I�u�W�F�N�g
		Font^ font;				//�t�H���g


		int _colCount;	//��
		int _rowCount;	//�s��



	public:
		int cellWidth;	//�Z���̕�
		int cellHeight;	//�Z���̍���

		ChainData* cell;

		TextBox^ text;	//�e�L�X�g�{�b�N�X
						//�񐔂̃v���p�e�B�[
		property int colCount {
			int get() {
				return _colCount;
			}
			void set(int col) {
				_colCount = col;
			}
		}
		//�s���̃v���p�e�B�[
		property int rowCount {
			int get() {
				return _rowCount;
			}
			void set(int row) {
				_rowCount = row;
			}
		}
		//���ݑI�𒆂̃Z��
		Cell^ currentCell;

		//�R���X�g���N�^
		DataGridSelfMade(PictureBox^ pictureBox);

		//�N���b�N���ꂽ�Ƃ��̓���
		Void cell_click(EventArgs^ e);
		Void cell_click(int row, int col);
		Void cell_click(Cell^ cell);

		//�w��̍s�A��Ɉ����̐F�̃Z����`�悷��֐�
		Void drawCell(int row, int col, Brush^ color);
		//�������Z���̎�
		Void drawCell(Cell^ cell, Brush ^ color);

		//�s���Ƃ̕`����s���֐�
		Void drawRow(int row, Brush^ color);
		//�������Z���̎�(�I�[�o�[���C�h)
		Void drawRow(Cell^ cell, Brush^ color);

		//�S�̂��ꂩ��`�悷�郁�\�b�h
		Void Paint();
		//�\�����̃f�[�^���N���A����֐�
		//Void Clear();

	private:/*
		Void textboxEnter(System::Object^  sender, Windows::Forms::KeyEventArgs^  e);
		Void textboxLostFocus(System::Object ^ sender, EventArgs ^ e);*/
	};

}

