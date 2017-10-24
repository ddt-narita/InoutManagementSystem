#pragma once

#include "Constants.h"
#include "procedureInOut.h"
#include "RegistForm.h"
#include "InoutForm.h"
#include "PassCheckForm.h"

namespace {
	Constants constants;
};

namespace InOutManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GuiMain �̊T�v
	/// </summary>
	public ref class GuiMain : public System::Windows::Forms::Form
	{
	public:
		GuiMain(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~GuiMain()
		{
			if (components)
			{
				delete components;
			}
		}


	protected:


	protected:

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(446, 321);
			this->Name = L"GuiMain";
			this->Text = L"GuiMain";
			this->Load += gcnew System::EventHandler(this, &GuiMain::GuiMain_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:

	private:
		System::Void GuiMain_Load(System::Object^  sender, System::EventArgs^  e) {
			//�J�[�h�҂����J�n����
			while(true) {
				//���������J�[�h���Ƃ̃f�[�^����������N���X�̃C���X�^���X�𐶐�����
				procedureInOut* procedureinout = new procedureInOut();
				//�J�[�h���[�_�Ƃ̏��������s��
				procedureinout->init();
				//�J�[�h�����������܂ő҂�
				procedureinout->card.getStatusChange(INFINITE);
				//�ҏW�t�H�[���̃C���X�^���X�𐶐�����
				inoutForm^ edit = gcnew inoutForm();
				//�t�H�[���̃f�[�^��
				edit->inoutData = procedureinout;
				//�t�H�[����\������
				edit->ShowDialog();
				//���̐l�̃f�[�^���擾���邽�߂��̃N���X�͕K�v�Ȃ��ō폜����
				delete procedureinout;
			}

		}
	};
}
