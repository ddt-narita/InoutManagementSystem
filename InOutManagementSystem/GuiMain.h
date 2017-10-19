#pragma once

#include "Constants.h"
#include "procedureInOut.h"
#include "RegistForm.h"
#include "EditForm.h"
#include "PassCheckForm.h"

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
	private: System::Windows::Forms::Button^  buttonIn;
	private: System::Windows::Forms::Button^  buttonOut;
	private: System::Windows::Forms::Button^  buttonRegister;
	private: System::Windows::Forms::Label^  labelIn;

	private: System::Windows::Forms::Label^  labelOut;


	private: System::Windows::Forms::Button^  buttonDataView;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Label^  labelCautionNeed;





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
			this->buttonIn = (gcnew System::Windows::Forms::Button());
			this->buttonOut = (gcnew System::Windows::Forms::Button());
			this->buttonRegister = (gcnew System::Windows::Forms::Button());
			this->labelIn = (gcnew System::Windows::Forms::Label());
			this->labelOut = (gcnew System::Windows::Forms::Label());
			this->buttonDataView = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->labelCautionNeed = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonIn
			// 
			this->buttonIn->Location = System::Drawing::Point(323, 12);
			this->buttonIn->Name = L"buttonIn";
			this->buttonIn->Size = System::Drawing::Size(69, 56);
			this->buttonIn->TabIndex = 0;
			this->buttonIn->Text = L"����";
			this->buttonIn->UseVisualStyleBackColor = true;
			this->buttonIn->Click += gcnew System::EventHandler(this, &GuiMain::buttonInOut_Click);
			// 
			// buttonOut
			// 
			this->buttonOut->Location = System::Drawing::Point(398, 12);
			this->buttonOut->Name = L"buttonOut";
			this->buttonOut->Size = System::Drawing::Size(69, 56);
			this->buttonOut->TabIndex = 1;
			this->buttonOut->Text = L"�ފ�";
			this->buttonOut->UseVisualStyleBackColor = true;
			this->buttonOut->Click += gcnew System::EventHandler(this, &GuiMain::buttonInOut_Click);
			// 
			// buttonRegister
			// 
			this->buttonRegister->Location = System::Drawing::Point(24, 12);
			this->buttonRegister->Name = L"buttonRegister";
			this->buttonRegister->Size = System::Drawing::Size(69, 56);
			this->buttonRegister->TabIndex = 2;
			this->buttonRegister->Text = L"�o�^";
			this->buttonRegister->UseVisualStyleBackColor = true;
			this->buttonRegister->Click += gcnew System::EventHandler(this, &GuiMain::buttonRegister_Click);
			// 
			// labelIn
			// 
			this->labelIn->AutoSize = true;
			this->labelIn->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 42, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelIn->Location = System::Drawing::Point(146, 170);
			this->labelIn->Name = L"labelIn";
			this->labelIn->Size = System::Drawing::Size(136, 56);
			this->labelIn->TabIndex = 3;
			this->labelIn->Text = L"����";
			this->labelIn->Visible = false;
			// 
			// labelOut
			// 
			this->labelOut->AutoSize = true;
			this->labelOut->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 42, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelOut->Location = System::Drawing::Point(146, 170);
			this->labelOut->Name = L"labelOut";
			this->labelOut->Size = System::Drawing::Size(136, 56);
			this->labelOut->TabIndex = 4;
			this->labelOut->Text = L"�ފ�";
			this->labelOut->Visible = false;
			// 
			// buttonDataView
			// 
			this->buttonDataView->Location = System::Drawing::Point(99, 12);
			this->buttonDataView->Name = L"buttonDataView";
			this->buttonDataView->Size = System::Drawing::Size(69, 56);
			this->buttonDataView->TabIndex = 6;
			this->buttonDataView->Text = L"���\��";
			this->buttonDataView->UseVisualStyleBackColor = true;
			this->buttonDataView->Click += gcnew System::EventHandler(this, &GuiMain::buttonDataView_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->Location = System::Drawing::Point(174, 12);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(69, 56);
			this->buttonEdit->TabIndex = 7;
			this->buttonEdit->Text = L"�ҏW";
			this->buttonEdit->UseVisualStyleBackColor = true;
			this->buttonEdit->Visible = false;
			// 
			// labelCautionNeed
			// 
			this->labelCautionNeed->AutoSize = true;
			this->labelCautionNeed->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelCautionNeed->Location = System::Drawing::Point(65, 246);
			this->labelCautionNeed->Name = L"labelCautionNeed";
			this->labelCautionNeed->Size = System::Drawing::Size(308, 48);
			this->labelCautionNeed->TabIndex = 8;
			this->labelCautionNeed->Text = L"�I�v���Ӑl��";
			this->labelCautionNeed->Visible = false;
			// 
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(472, 315);
			this->Controls->Add(this->labelCautionNeed);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->buttonDataView);
			this->Controls->Add(this->labelOut);
			this->Controls->Add(this->labelIn);
			this->Controls->Add(this->buttonRegister);
			this->Controls->Add(this->buttonOut);
			this->Controls->Add(this->buttonIn);
			this->Name = L"GuiMain";
			this->Text = L"GuiMain";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		procedureInOut* procedureInout;

		/*
		�֐���:labelsOff
		�T�v:���x���Q���\���ɂ���
		����:����
		�ԋp�l:����
		�쐬��:10��18��(��)
		�쐬��:���c�C�V
		*/
		Void labelsOff() {
			//���x�������ׂĔ�\����
			this->labelIn->Visible = false;
			this->labelOut->Visible = false;
			this->labelCautionNeed->Visible = false;
		}

		/*
		�֐���:CheckCharacter
		�T�v:�l���̃`�F�b�N���s��
		����:�Ȃ�
		�ԋp�l:�Ȃ�
		�쐬��:10��18��(��)
		�쐬��:���c�C�V
		*/
		Void CheckCharacter() {
			//�l���̒l���擾����
			int character = procedureInout->getCharacter();

			//�擾�����l�ŕ���
			switch (character) {
				//�����̎�
			case 0:
				//���������ɔ�����
				break;
				//���ً��ێ҂̎�
			case 1:
				//��O�𑗏o����
				throw std::exception();
				///������
				break;
				//�v���Ӑl���̎�
			case 2:
				//���̂��Ƃ��������x����\������
				labelCautionNeed->Visible = true;
				//������
				break;
			}
		}


	private:
		System::Void buttonInOut_Click(System::Object^  sender, System::EventArgs^  e) {
			//���̃C�x���g���N�������{�^�����擾����
			Button^ inoutButton = (Button^)sender;
			//���o�Ă��郉�x���Q�������Ȃ�����
			labelsOff();
			//���ފُ������s���N���X�̃C���X�^���X�𐶐�����
			procedureInout = new procedureInOut();
			//�����ꂽ�{�^���ɂ���ē��ޏ����N���X�ɓn���l�����ꂼ��ɂ���
			procedureInout->inout = (inoutButton->Name == "buttonIn" ? INOUT::In : INOUT::Out);
			try {
				//�J�[�h���[�_���̏��������s��
				procedureInout->init();
				//���ފُ��������s����
				procedureInout->InOut();
				CheckCharacter();
				//���ك{�^������̎�
				if (inoutButton->Name == "buttonIn") {
					//���ق��������������i�[
					labelIn->Visible = true;
				}
				//�ފك{�^������̎�
				else {
					//�ފق������l���i�[
					labelOut->Visible = true;
				}
			}
			catch (std::exception& e) {
				//�G���[�̃��b�Z�[�W�����̂܂ܕ\������
				MessageBox::Show(gcnew String(e.what()), "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
			finally{
				//�J�[�h���[�_�̃N���A����
				procedureInout->clear();
			}
		}

	private:
		System::Void buttonRegister_Click(System::Object^  sender, System::EventArgs^  e) {
			RegistForm^ registform = gcnew RegistForm();
			registform->ShowDialog();
		}

	private:
		System::Void buttonDataView_Click(System::Object^  sender, System::EventArgs^  e) {

			//�J�[�h���������w�����o��
			Windows::Forms::DialogResult dr = MessageBox::Show("����\���������J�[�h���������Ă�������", "", MessageBoxButtons::OKCancel, MessageBoxIcon::None);

			if (dr == Windows::Forms::DialogResult::Cancel) {
				return;
			}

			//�J�[�h�̃f�[�^���擾���邽�߂̃I�u�W�F�N�g�𐶐�
			DataManager* cardData = new DataManager();

			try {
				//�J�[�h���[�_�̏��������s��
				cardData->init();
				//�J�[�h��ID�̂ݓǂݍ���
				cardData->readCardId();
				//�J�[�h�̃f�[�^���t�@�C������擾����
				cardData->readFileData();
				//�p�X���[�h���`�F�b�N����
				password_check(cardData);

				//�ҏW�t�H�[�����쐻����
				EditForm^ editForm = gcnew EditForm();
				//�ҏW�t�H�[���ɃJ�[�h�̃f�[�^��n��
				editForm->editData = cardData;
				//�\���{�^�����痈�����Ƃ������l��n��
				editForm->buttonFrom = 1;
				//�ҏW�t�H�[����\������
				editForm->ShowDialog();
			}
			catch (std::exception& e) {
				MessageBox::Show(gcnew String(e.what()), "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}



		Void password_check(DataManager* cardData) {
			PassCheckForm^ passform = gcnew PassCheckForm();

			//
			passform->id = cardData->userId;
			passform->name = gcnew String(cardData->userName.c_str());
			passform->password = gcnew String(cardData->password.c_str());
			passform->ShowDialog();

			//
			if (!passform->Judge) {
				//
				throw std::exception("�\�����������f����܂����B");
			}
		}
	};
}
