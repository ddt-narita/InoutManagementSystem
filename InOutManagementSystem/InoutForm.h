#pragma once

#include "DataManager.h"
#include "DataGridSelfMade.h"

namespace InOutManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// inoutForm �̊T�v
	/// </summary>
	public ref class inoutForm : public System::Windows::Forms::Form
	{
	public:
		inoutForm(void)
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
		~inoutForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^  labelID;

	private: System::Windows::Forms::TextBox^  textBoxID;
	private: System::Windows::Forms::Label^  labelLastName;
	private: System::Windows::Forms::TextBox^  textBoxLastName;






	private: System::Windows::Forms::Label^  labelBirthday;

	private: System::Windows::Forms::TextBox^  textBoxTell;




	private: System::Windows::Forms::Label^  labelTell;
	private: System::Windows::Forms::Label^  labelAddress;
	private: System::Windows::Forms::TextBox^  textBoxAddress;
	private: System::Windows::Forms::ComboBox^  comboBoxAffili;


	private: System::Windows::Forms::ComboBox^  comboBoxCast;
	private: System::Windows::Forms::ComboBox^  comboBoxAuthority;
	private: System::Windows::Forms::Label^  labelAffili;








	private: System::Windows::Forms::Label^  labelCast;
	private: System::Windows::Forms::Label^  labelAttr;
	private: System::Windows::Forms::Label^  labelAuthority;
	private: System::Windows::Forms::Label^  labelCharacter;
	private: System::Windows::Forms::ComboBox^  comboBoxCharacter;





	private: System::Windows::Forms::Label^  labelInoutYM;
	private: System::Windows::Forms::TextBox^  textBoxInoutY;
	private: System::Windows::Forms::Label^  labelInoutY;
	private: System::Windows::Forms::TextBox^  textBoxInoutM;
	private: System::Windows::Forms::Label^  labelInoutM;




	private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirthday;






	private: System::Windows::Forms::Label^  labelFirstName;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;
	private: System::Windows::Forms::Label^  labelGroup;
	private: System::Windows::Forms::ComboBox^  comboBoxGroup;
	private: System::Windows::Forms::Button^  buttonIn;
	private: System::Windows::Forms::Button^  buttonOut;
	private: System::Windows::Forms::Button^  buttonInoutView;











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
			this->labelID = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->labelBirthday = (gcnew System::Windows::Forms::Label());
			this->textBoxTell = (gcnew System::Windows::Forms::TextBox());
			this->labelTell = (gcnew System::Windows::Forms::Label());
			this->labelAddress = (gcnew System::Windows::Forms::Label());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->comboBoxAffili = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxCast = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxAuthority = (gcnew System::Windows::Forms::ComboBox());
			this->labelAffili = (gcnew System::Windows::Forms::Label());
			this->labelCast = (gcnew System::Windows::Forms::Label());
			this->labelAttr = (gcnew System::Windows::Forms::Label());
			this->labelAuthority = (gcnew System::Windows::Forms::Label());
			this->labelCharacter = (gcnew System::Windows::Forms::Label());
			this->comboBoxCharacter = (gcnew System::Windows::Forms::ComboBox());
			this->labelInoutYM = (gcnew System::Windows::Forms::Label());
			this->textBoxInoutY = (gcnew System::Windows::Forms::TextBox());
			this->labelInoutY = (gcnew System::Windows::Forms::Label());
			this->textBoxInoutM = (gcnew System::Windows::Forms::TextBox());
			this->labelInoutM = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerBirthday = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->labelGroup = (gcnew System::Windows::Forms::Label());
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->buttonIn = (gcnew System::Windows::Forms::Button());
			this->buttonOut = (gcnew System::Windows::Forms::Button());
			this->buttonInoutView = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// labelID
			// 
			this->labelID->AutoSize = true;
			this->labelID->Location = System::Drawing::Point(50, 108);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(16, 12);
			this->labelID->TabIndex = 2;
			this->labelID->Text = L"ID";
			// 
			// textBoxID
			// 
			this->textBoxID->Location = System::Drawing::Point(72, 105);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(144, 19);
			this->textBoxID->TabIndex = 0;
			// 
			// labelLastName
			// 
			this->labelLastName->AutoSize = true;
			this->labelLastName->Location = System::Drawing::Point(37, 143);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(29, 12);
			this->labelLastName->TabIndex = 4;
			this->labelLastName->Text = L"�c��";
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Location = System::Drawing::Point(72, 136);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(144, 19);
			this->textBoxLastName->TabIndex = 1;
			// 
			// labelBirthday
			// 
			this->labelBirthday->AutoSize = true;
			this->labelBirthday->Location = System::Drawing::Point(14, 202);
			this->labelBirthday->Name = L"labelBirthday";
			this->labelBirthday->Size = System::Drawing::Size(53, 12);
			this->labelBirthday->TabIndex = 6;
			this->labelBirthday->Text = L"���N����";
			// 
			// textBoxTell
			// 
			this->textBoxTell->Location = System::Drawing::Point(73, 232);
			this->textBoxTell->Name = L"textBoxTell";
			this->textBoxTell->Size = System::Drawing::Size(144, 19);
			this->textBoxTell->TabIndex = 4;
			// 
			// labelTell
			// 
			this->labelTell->AutoSize = true;
			this->labelTell->Location = System::Drawing::Point(14, 235);
			this->labelTell->Name = L"labelTell";
			this->labelTell->Size = System::Drawing::Size(53, 12);
			this->labelTell->TabIndex = 11;
			this->labelTell->Text = L"�d�b�ԍ�";
			// 
			// labelAddress
			// 
			this->labelAddress->AutoSize = true;
			this->labelAddress->Location = System::Drawing::Point(263, 121);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(29, 12);
			this->labelAddress->TabIndex = 12;
			this->labelAddress->Text = L"�Z��";
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(304, 118);
			this->textBoxAddress->Multiline = true;
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(276, 60);
			this->textBoxAddress->TabIndex = 7;
			// 
			// comboBoxAffili
			// 
			this->comboBoxAffili->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAffili->FormattingEnabled = true;
			this->comboBoxAffili->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"�c��", L"����", L"�J��" });
			this->comboBoxAffili->Location = System::Drawing::Point(304, 184);
			this->comboBoxAffili->Name = L"comboBoxAffili";
			this->comboBoxAffili->Size = System::Drawing::Size(121, 20);
			this->comboBoxAffili->TabIndex = 8;
			// 
			// comboBoxCast
			// 
			this->comboBoxCast->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCast->FormattingEnabled = true;
			this->comboBoxCast->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"���Ј�", L"�p�[�g", L"����" });
			this->comboBoxCast->Location = System::Drawing::Point(306, 237);
			this->comboBoxCast->Name = L"comboBoxCast";
			this->comboBoxCast->Size = System::Drawing::Size(121, 20);
			this->comboBoxCast->TabIndex = 10;
			// 
			// comboBoxAuthority
			// 
			this->comboBoxAuthority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAuthority->FormattingEnabled = true;
			this->comboBoxAuthority->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"�{����", L"�Ǘ���" });
			this->comboBoxAuthority->Location = System::Drawing::Point(348, 263);
			this->comboBoxAuthority->Name = L"comboBoxAuthority";
			this->comboBoxAuthority->Size = System::Drawing::Size(121, 20);
			this->comboBoxAuthority->TabIndex = 11;
			// 
			// labelAffili
			// 
			this->labelAffili->AutoSize = true;
			this->labelAffili->Location = System::Drawing::Point(263, 187);
			this->labelAffili->Name = L"labelAffili";
			this->labelAffili->Size = System::Drawing::Size(29, 12);
			this->labelAffili->TabIndex = 17;
			this->labelAffili->Text = L"����";
			// 
			// labelCast
			// 
			this->labelCast->AutoSize = true;
			this->labelCast->Location = System::Drawing::Point(265, 240);
			this->labelCast->Name = L"labelCast";
			this->labelCast->Size = System::Drawing::Size(29, 12);
			this->labelCast->TabIndex = 18;
			this->labelCast->Text = L"��E";
			// 
			// labelAttr
			// 
			this->labelAttr->AutoSize = true;
			this->labelAttr->Location = System::Drawing::Point(265, 266);
			this->labelAttr->Name = L"labelAttr";
			this->labelAttr->Size = System::Drawing::Size(29, 12);
			this->labelAttr->TabIndex = 19;
			this->labelAttr->Text = L"����";
			// 
			// labelAuthority
			// 
			this->labelAuthority->AutoSize = true;
			this->labelAuthority->Location = System::Drawing::Point(304, 266);
			this->labelAuthority->Name = L"labelAuthority";
			this->labelAuthority->Size = System::Drawing::Size(29, 12);
			this->labelAuthority->TabIndex = 20;
			this->labelAuthority->Text = L"����";
			// 
			// labelCharacter
			// 
			this->labelCharacter->AutoSize = true;
			this->labelCharacter->Location = System::Drawing::Point(304, 292);
			this->labelCharacter->Name = L"labelCharacter";
			this->labelCharacter->Size = System::Drawing::Size(29, 12);
			this->labelCharacter->TabIndex = 21;
			this->labelCharacter->Text = L"�l��";
			// 
			// comboBoxCharacter
			// 
			this->comboBoxCharacter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCharacter->FormattingEnabled = true;
			this->comboBoxCharacter->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"����", L"���ً���", L"�v���Ӑl��" });
			this->comboBoxCharacter->Location = System::Drawing::Point(348, 289);
			this->comboBoxCharacter->Name = L"comboBoxCharacter";
			this->comboBoxCharacter->Size = System::Drawing::Size(121, 20);
			this->comboBoxCharacter->TabIndex = 12;
			// 
			// labelInoutYM
			// 
			this->labelInoutYM->AutoSize = true;
			this->labelInoutYM->Location = System::Drawing::Point(11, 280);
			this->labelInoutYM->Name = L"labelInoutYM";
			this->labelInoutYM->Size = System::Drawing::Size(65, 12);
			this->labelInoutYM->TabIndex = 24;
			this->labelInoutYM->Text = L"���ފٔN��";
			// 
			// textBoxInoutY
			// 
			this->textBoxInoutY->Location = System::Drawing::Point(92, 277);
			this->textBoxInoutY->Name = L"textBoxInoutY";
			this->textBoxInoutY->Size = System::Drawing::Size(36, 19);
			this->textBoxInoutY->TabIndex = 5;
			// 
			// labelInoutY
			// 
			this->labelInoutY->AutoSize = true;
			this->labelInoutY->Location = System::Drawing::Point(134, 280);
			this->labelInoutY->Name = L"labelInoutY";
			this->labelInoutY->Size = System::Drawing::Size(17, 12);
			this->labelInoutY->TabIndex = 26;
			this->labelInoutY->Text = L"�N";
			// 
			// textBoxInoutM
			// 
			this->textBoxInoutM->Location = System::Drawing::Point(157, 277);
			this->textBoxInoutM->Name = L"textBoxInoutM";
			this->textBoxInoutM->Size = System::Drawing::Size(36, 19);
			this->textBoxInoutM->TabIndex = 6;
			// 
			// labelInoutM
			// 
			this->labelInoutM->AutoSize = true;
			this->labelInoutM->Location = System::Drawing::Point(199, 280);
			this->labelInoutM->Name = L"labelInoutM";
			this->labelInoutM->Size = System::Drawing::Size(17, 12);
			this->labelInoutM->TabIndex = 28;
			this->labelInoutM->Text = L"��";
			// 
			// dateTimePickerBirthday
			// 
			this->dateTimePickerBirthday->Location = System::Drawing::Point(73, 197);
			this->dateTimePickerBirthday->Name = L"dateTimePickerBirthday";
			this->dateTimePickerBirthday->Size = System::Drawing::Size(144, 19);
			this->dateTimePickerBirthday->TabIndex = 3;
			// 
			// labelFirstName
			// 
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Location = System::Drawing::Point(37, 166);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(29, 12);
			this->labelFirstName->TabIndex = 37;
			this->labelFirstName->Text = L"���O";
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Location = System::Drawing::Point(73, 163);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(144, 19);
			this->textBoxFirstName->TabIndex = 2;
			// 
			// labelGroup
			// 
			this->labelGroup->AutoSize = true;
			this->labelGroup->Location = System::Drawing::Point(249, 213);
			this->labelGroup->Name = L"labelGroup";
			this->labelGroup->Size = System::Drawing::Size(43, 12);
			this->labelGroup->TabIndex = 39;
			this->labelGroup->Text = L"�O���[�v";
			// 
			// comboBoxGroup
			// 
			this->comboBoxGroup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxGroup->FormattingEnabled = true;
			this->comboBoxGroup->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"���O���[�v", L"���O���[�v", L"��O�O���[�v" });
			this->comboBoxGroup->Location = System::Drawing::Point(306, 210);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(121, 20);
			this->comboBoxGroup->TabIndex = 9;
			// 
			// buttonIn
			// 
			this->buttonIn->Location = System::Drawing::Point(12, 12);
			this->buttonIn->Name = L"buttonIn";
			this->buttonIn->Size = System::Drawing::Size(73, 46);
			this->buttonIn->TabIndex = 40;
			this->buttonIn->Text = L"����";
			this->buttonIn->UseVisualStyleBackColor = true;
			this->buttonIn->Click += gcnew System::EventHandler(this, &inoutForm::buttonInOut_Click);
			// 
			// buttonOut
			// 
			this->buttonOut->Location = System::Drawing::Point(91, 12);
			this->buttonOut->Name = L"buttonOut";
			this->buttonOut->Size = System::Drawing::Size(72, 46);
			this->buttonOut->TabIndex = 41;
			this->buttonOut->Text = L"�ފ�";
			this->buttonOut->UseVisualStyleBackColor = true;
			this->buttonOut->Click += gcnew System::EventHandler(this, &inoutForm::buttonInOut_Click);
			// 
			// buttonInoutView
			// 
			this->buttonInoutView->Location = System::Drawing::Point(306, 12);
			this->buttonInoutView->Name = L"buttonInoutView";
			this->buttonInoutView->Size = System::Drawing::Size(59, 46);
			this->buttonInoutView->TabIndex = 42;
			this->buttonInoutView->Text = L"���ފوꗗ";
			this->buttonInoutView->UseVisualStyleBackColor = true;
			this->buttonInoutView->Click += gcnew System::EventHandler(this, &inoutForm::buttonInoutView_Click);
			// 
			// inoutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 339);
			this->Controls->Add(this->buttonInoutView);
			this->Controls->Add(this->buttonOut);
			this->Controls->Add(this->buttonIn);
			this->Controls->Add(this->comboBoxGroup);
			this->Controls->Add(this->labelGroup);
			this->Controls->Add(this->textBoxFirstName);
			this->Controls->Add(this->labelFirstName);
			this->Controls->Add(this->dateTimePickerBirthday);
			this->Controls->Add(this->labelInoutM);
			this->Controls->Add(this->textBoxInoutM);
			this->Controls->Add(this->labelInoutY);
			this->Controls->Add(this->textBoxInoutY);
			this->Controls->Add(this->labelInoutYM);
			this->Controls->Add(this->comboBoxCharacter);
			this->Controls->Add(this->labelCharacter);
			this->Controls->Add(this->labelAuthority);
			this->Controls->Add(this->labelAttr);
			this->Controls->Add(this->labelCast);
			this->Controls->Add(this->labelAffili);
			this->Controls->Add(this->comboBoxAuthority);
			this->Controls->Add(this->comboBoxCast);
			this->Controls->Add(this->comboBoxAffili);
			this->Controls->Add(this->textBoxAddress);
			this->Controls->Add(this->labelAddress);
			this->Controls->Add(this->labelTell);
			this->Controls->Add(this->textBoxTell);
			this->Controls->Add(this->labelBirthday);
			this->Controls->Add(this->textBoxLastName);
			this->Controls->Add(this->labelLastName);
			this->Controls->Add(this->textBoxID);
			this->Controls->Add(this->labelID);
			this->Name = L"inoutForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EditForm";
			this->Load += gcnew System::EventHandler(this, &inoutForm::EditForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		procedureInOut* inoutData;

	private:

		System::Void applyControls() {
			//��{���𕶎���ɕς��ė^����
			textBoxID->Text = gcnew String(inoutData->userId.c_str());
			//�c����n��
			textBoxLastName->Text = gcnew String(inoutData->userLastName.c_str());
			//���O��n��
			textBoxFirstName->Text = gcnew String(inoutData->userFirstName.c_str());
			//�d�b�ԍ���n��
			textBoxTell->Text = gcnew String(inoutData->telNo.c_str());
			//�Z����n��
			textBoxAddress->Text = gcnew String(inoutData->address.c_str());

			//�ǉ������R���{�{�b�N�X�̑I��l�Ƃ��Ċi�[����
			comboBoxAffili->SelectedIndex = inoutData->getSelectedAffli();
			comboBoxGroup->SelectedIndex = inoutData->getSelectedGroup();
			comboBoxCast->SelectedIndex = inoutData->getSelectedCast();
			comboBoxAuthority->SelectedIndex = inoutData->getSelectedAuth();
			comboBoxCharacter->SelectedIndex = inoutData->getSelectedChara();


			//�a�����̒l����N�������v�Z���Ď擾
			int year = inoutData->birthday / 10000;
			int month = (inoutData->birthday / 100) - (year * 100);
			int day = (inoutData->birthday) - (year * 10000) - (month * 100);

			//�擾�����N�����œ��t���쐻
			DateTime date(year, month, day);
			//�t�H�[���̒a�����I���̒l�Ƃ��ēn��
			dateTimePickerBirthday->Value = date;

			//���ނ̔N����n��
			textBoxInoutY->Text = inoutData->getInoutY().ToString();
			textBoxInoutM->Text = inoutData->getInoutM().ToString();
			//�t�H�[���̊e����ǂݍ��ݐ�p�ɂ���
			setReadOnly();

		}



		System::Void EditForm_Load(System::Object^  sender, System::EventArgs^  e) {

			inoutData->card.connectCard();
			try {
				//�J�[�h�̃f�[�^��ǂݍ���
				inoutData->readCardData();
				//ID�̃`�F�b�N���s��
				inoutData->checkId();
				//�l���̃`�F�b�N���s��
				inoutData->checkCharacter();
				//�t�@�C������O��܂ł̏����擾���ă����o�Ɋi�[����
				inoutData->readFileData();
				//�O��܂ł̃f�[�^���J�[�h�ւƏ����o��
				inoutData->writeCard();
				//�t�H�[�����
				applyControls();
				//���ُ�Ԃ̃`�F�b�N���s��
				inoutData->inoutCheck();
			}
			//��O�����������Ƃ�
			catch (std::exception& e) {
				//��O�ɓY����ꂽ���b�Z�[�W�����b�Z�[�W�{�b�N�X�Ōx�����o��
				MessageBox::Show(gcnew String(e.what()), "�x��", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}

		/*
		�֐���:setReadOnly
		�T�v:�ҏW�\�ȃt�H�[����ҏW�s�ɂ���(�\���݂̂ɂ���)
		����:�Ȃ�
		�ԋp�l:�Ȃ�
		�쐬��:10��18��(��)
		�쐬��:���c�C�V
		*/
		void setReadOnly() {
			//�e�L�X�g�{�b�N�X��ǂݐ�p�ɂ���
			textBoxID->ReadOnly = true;			//ID
			textBoxFirstName->ReadOnly = true;	//���O
			textBoxLastName->ReadOnly = true;	//�c��
			textBoxAddress->ReadOnly = true;	//�Z��
			textBoxTell->ReadOnly = true;		//�d�b
			textBoxInoutY->ReadOnly = true;		//�N
			textBoxInoutM->ReadOnly = true;		//��

			//�R���{�{�b�N�X���h���b�v�_�E���ł��Ȃ�����
			comboBoxGroup->Enabled = false;		//�O���[�v
			comboBoxAffili->Enabled = false;	//����
			comboBoxCast->Enabled = false;		//��E
			comboBoxAuthority->Enabled = false;	//����
			comboBoxCharacter->Enabled = false;	//�l��

			//���t�I���R���g���[�����I���ł��Ȃ�����
			dateTimePickerBirthday->Enabled = false;
		}


	private:
		System::Void buttonInOut_Click(System::Object^  sender, System::EventArgs^  e) {
			//���ق��ފق̃C�x���g���N�������{�^�����擾����
			Button^ inoutButton = (Button^)sender;
			//���ك{�^������Ȃ���ފُ����̃N���X�ɓ��ق̒l���A�ފك{�^���Ȃ�ފق̒l��n��
			inoutData->inout = (inoutButton->Name == "buttonIn" ? INOUT::In : INOUT::Out);
			try {
				//���ފُ������s��
				inoutData->InOut();
				//��O�ɓY����ꂽ���b�Z�[�W�����b�Z�[�W�{�b�N�X�Ōx�����o��
				MessageBox::Show("�t�@�C���ւ̏������݊����I", "����", MessageBoxButtons::OK, MessageBoxIcon::None);
			}
			catch (std::exception& e) {
				//��O�ɓY����ꂽ���b�Z�[�W�����b�Z�[�W�{�b�N�X�Ōx�����o��
				MessageBox::Show(gcnew String(e.what()), "�x��", MessageBoxButtons::OK, MessageBoxIcon::Hand);
			}
		}
	private: System::Void buttonInoutView_Click(System::Object^  sender, System::EventArgs^  e) {


	}
};
}
