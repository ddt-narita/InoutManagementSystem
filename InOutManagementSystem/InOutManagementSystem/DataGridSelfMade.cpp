#include "DataGridSelfMade.h"



using namespace narita;

/*
�֐���:�R���X�g���N�^
�T�v:�`���̃s�N�`���[�{�b�N�X���󂯎���Ă��ꂩ��͂����֔z�u����
����:PictureBox^ pictureBox�@�`�悵�����̂̔z�u��
�ԋp�l:����
�쐬��:9��9��
�쐬��:���c�C�V
*/
DataGridSelfMade::DataGridSelfMade(PictureBox^ pictureBox)
{
	//�󂯎�����`�悵�����̂�z�u����I�u�W�F�N�g�������o�ɋ��L
	(this->pictureBox) = pictureBox;
	//�Z�����Ƃ̃N���X������
	//������
	colCount = 1;
	//�����s��
	rowCount = 1;
	//�Z���̕�
	cellWidth = 60;
	//�Z���̍���
	cellHeight = 20;
	//�J�����g�Z�����쐬
	currentCell = gcnew narita::Cell();
	cell = new ChainData();

	//�Z���̘g��`���y���I�u�W�F�N�g���쐬
	cellFramePen = gcnew Pen(Color::Black, 3);
	//������������Ƃ��̃t�H���g
	font = gcnew Font("�l�r �S�V�b�N", 9);

	//�`��Ώۂ̃C���[�W�I�u�W�F�N�g
	this->canvas = gcnew Bitmap(this->pictureBox->Width - 1, this->pictureBox->Height - 1);
	//�쐬�����C���[�W�I�u�W�F�N�g���s�N�`���{�b�N�X�ɔz�u
	this->pictureBox->Image = this->canvas;
	//�s�N�`���{�b�N�X�`��Ώۂɕ`�����߂̃I�u�W�F�N�g���쐬
	this->graphic = Graphics::FromImage(this->pictureBox->Image);
	//�I�����ꂽ�Z���ɕ\������e�L�X�g�{�b�N�X��\������
	text = gcnew TextBox();
	text->Multiline = true;
	text->AutoSize = false;
	text->ImeMode = ImeMode::Off;
	pictureBox->Controls->Add(text);
	//text->KeyDown += gcnew KeyEventHandler(this, &DataGridSelfMade::textboxEnter);
	//text->LostFocus += gcnew EventHandler(this, &DataGridSelfMade::textboxLostFocus);
	text->BackColor = Color::Aqua;
	text->Visible = false;
}



/*
�֐���:Cell_click
�T�v:�Z�����N���b�N���ꂽ�Ƃ��̊֐�
����:int row�@�Z���̍s, int col�@�Z���̗�
�ԋp�l:�Ȃ�
�쐬��:9��10��
�쐬��:���c�C�V
*/
Void narita::DataGridSelfMade::cell_click(int row, int col)
{
	//�s�񂪖����Ȓl�Ȃ�
	if (row < 0 || col < 0) {
		//��������߂�
		return;
	}

	//����܂ł̃J�����g�̃Z�����L���ȃZ���ł���Ȃ�
	if (0 <= currentCell->row && 0 <= currentCell->col) {
		//���̍s�����Ƃ̐F�ŕ`��
		drawRow(currentCell, Brushes::White);
	}

	//�J�����g�̃Z���������̒l�ɂ���
	currentCell->row = row;
	currentCell->col = col;
	
	//�J�����g�̍s�𐅐F�ŕ`��
	drawRow(currentCell, Brushes::Aqua);

	//�`��𑣂��ĕύX�𔽉f
	pictureBox->Invalidate();
}

/*
�֐���:cell_click
�T�v:�Z�����N���b�N���ꂽ�Ƃ��̊֐�(�I�[�o�[���[�h)
����:Cell^ cell �Z��
�ԋp�l:�Ȃ�
�쐬��:���c�C�V
�쐬��:9��15��(��)
*/
Void narita::DataGridSelfMade::cell_click(Cell ^ cell)
{
	//�����̃Z���̍s���񐔂œ����֐����Ăяo���B
	cell_click(cell->row, cell->col);
}

/*
�֐���:cell_Click
�T�v:�Z�����N���b�N���ꂽ�Ƃ��̓���
����:����
�ԋp�l:�Ȃ�
�쐬��:9��9��
�쐬��:���c�C�V
*/
Void DataGridSelfMade::cell_click(System::EventArgs^ e)
{
	int row = ((MouseEventArgs^)e)->Y / this->cellHeight;
	int col = ((MouseEventArgs^)e)->X / this->cellWidth;

	this->cell_click(row, col);

}

/*
�֐���:drawCell
�T�v:�Z����`�悷��
����:int row �s
	int col ��
	Brush^ color�@�Z���̐F
�ԋp�l:����
�쐬��:10��17��(��)
�쐬��:���c�C�V
*/
Void narita::DataGridSelfMade::drawCell(int row, int col, Brush ^ color)
{
	//�s�񂪗L���Ȓl�łȂ�
	if (0 > row || 0 > col) {
		//��������߂�
		return;
	}
	//�Z���ƂȂ�l�p�`���쐻����
	RectangleF^ rect = gcnew RectangleF(col * this->cellWidth, row * this->cellHeight, this->cellWidth - 1, this->cellHeight - 1);
	//�����̍s�̃f�[�^���擾����
	ChainData* rowData = cell->getRow(row);
	//�Z���̒l���i�[����ϐ���p��
	String^ value;
	//���ڂɂ��Ă̎�

		//���̗�̒l���i�[����
		value = rowData->getValue(col + 1).ToString();

	//�Z���̋�؂�̐���`��
	graphic->DrawLine(cellFramePen, Point(col * cellWidth, row * cellHeight), Point(col * cellWidth, (row + 1) * cellHeight));
	//�l�p�`�������̐F�Ŗ������Ă���
	graphic->FillRectangle(color, *rect);
	//�擾������������l�p�`�ɕ`��
	graphic->DrawString(value, font, Brushes::Black, *rect);
}

/*
�֐���:drawCell(�I�[�o�[���C�h)
�T�v:�Z����I�����ĕ`�悷��
����:Cell^�@�`�悵�����Z��
	Brush^�@���̍ۂ̐F
�ԋp�l:����
�쐬��:10��17��(��)
�쐬��:���c�C�V
*/
Void narita::DataGridSelfMade::drawCell(Cell ^ cell, Brush ^ color)
{
	//�I�[�o�[���C�h��ɍ��킹�Ă��̊֐����Ă�
	drawCell(cell->row, cell->col, color);
}

/*
�֐���:drawRow
�T�v:�s��`�悷��
����:int row �`�悷��s
	Brush^�@�F
�ԋp�l:����
�쐬��:10��17��(��)
�쐬��:���c�C�V
*/
Void narita::DataGridSelfMade::drawRow(int row, Brush ^ color)
{
	//�����̍s�������Ȓl�Ȃ�
	if (0 > row) {
		//��������߂�
		return;
	}

	//4�񕪌J��Ԃ�
	for (int i = 0; i < 4; i++) {
		//�e�Z����`��
		drawCell(row, i, color);
	}
}

/*
�֐���:drawRow(�I�[�o�[���C�h)
�T�v:�Z����I�����čs��`�悷��
����:Cell^�@�Z��
	Brush�O�@�F
�ԋp�l:����
�쐬��:10��17��(��)
�쐬��:���c�C�V
*/
Void narita::DataGridSelfMade::drawRow(Cell ^ cell, Brush ^ color)
{
	//�s�ƈ����̐F�ŕ`��
	drawRow(cell->row, color);
}

/*
�֐���:Paint
�T�v:���ׂẴZ����`�悷��
����:����
�ԋp�l:����
�쐬��:10��17��(��)
�쐬��:���c�C�V
*/
Void narita::DataGridSelfMade::Paint()
{
	//�s����̂ǂ��炩��0�Ȃ�\��������̂͂Ȃ��̂ŉ������Ȃ�
	if (rowCount == 0 || colCount == 0) {
		return;
	}
	//�s�N�`���[�{�b�N�X�̑傫����ݒ肳��Ă���s���񐔂ɍ��킹��
	pictureBox->Size = System::Drawing::Size(colCount * cellWidth, rowCount * cellHeight);
	//�s�N�`���[�{�b�N�X�̑傫���ɍ��킹�ĕ`���̃I�u�W�F�N�g�𐶐����Ȃ���
	pictureBox->Image = gcnew Bitmap(pictureBox->Width, pictureBox->Height);
	//���̕`���ɕ`�悷��I�u�W�F�N�g���쐬
	graphic = Graphics::FromImage(pictureBox->Image);

	//�s�����J��Ԃ�
	for (int i = 0; i < rowCount; i++) {
		//�s���Ƃɕ`��
		drawRow(i, Brushes::White);
		//�s���Ɛ���`��
		graphic->DrawLine(cellFramePen, Point(0, (i + 1) * cellHeight), Point(colCount * cellWidth, (i + 1) * cellHeight));
	}

	//���C���@�J�����g�̃Z���̂���s���Ȃ��Ȃ������Z���̒l���擾�ł�����
	//��O���o��̂ōs���񐔂�葽���Ƃ��̓J�����g�̃Z����`�悵�Ȃ�
	if (currentCell->row < rowCount && currentCell->col < colCount) {
		//�J�����g�̃Z���ɂ��ĕ`�悷��
		drawCell(currentCell, Brushes::Aqua);
	}
	
	return Void();
}
