#pragma once

#include "procedureRegist.h"

namespace InOutManagementSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// RegistForm �̊T�v
	/// </summary>
	public ref class RegistForm : public System::Windows::Forms::Form
	{
	public:
		RegistForm(void)
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
		~RegistForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirth;
	private: System::Windows::Forms::TextBox^  textBoxTel;
	protected:



	private: System::Windows::Forms::TextBox^  textBoxAddress;

	private: System::Windows::Forms::TextBox^  textBoxName;
	private: System::Windows::Forms::Label^  labelBirthDay;
	private: System::Windows::Forms::Label^  labelTel;




	private: System::Windows::Forms::Label^  labelAddress;

	private: System::Windows::Forms::Label^  labelName;
	private: System::Windows::Forms::Label^  labelID;
	private: System::Windows::Forms::TextBox^  textBoxID;
	private: System::Windows::Forms::ComboBox^  comboBoxGroup;
	private: System::Windows::Forms::Label^  labelGroup;
	private: System::Windows::Forms::ComboBox^  comboBoxCharacter;



	private: System::Windows::Forms::ComboBox^  comboBoxCast;
	private: System::Windows::Forms::Label^  labelAttr;


	private: System::Windows::Forms::Label^  labelCast;
	private: System::Windows::Forms::Button^  buttonCancel;
	private: System::Windows::Forms::Button^  buttonOK;
	private: System::Windows::Forms::ComboBox^  comboBoxAuth;

	private: System::Windows::Forms::Label^  labelCharacter;
	private: System::Windows::Forms::Label^  labelAuthority;
	private: System::Windows::Forms::TextBox^  textBoxPassword;
	private: System::Windows::Forms::Label^  labelPassword;



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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxPassword = (gcnew System::Windows::Forms::TextBox());
			this->labelPassword = (gcnew System::Windows::Forms::Label());
			this->comboBoxAuth = (gcnew System::Windows::Forms::ComboBox());
			this->labelCharacter = (gcnew System::Windows::Forms::Label());
			this->labelAuthority = (gcnew System::Windows::Forms::Label());
			this->comboBoxCharacter = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxCast = (gcnew System::Windows::Forms::ComboBox());
			this->labelAttr = (gcnew System::Windows::Forms::Label());
			this->labelCast = (gcnew System::Windows::Forms::Label());
			this->labelGroup = (gcnew System::Windows::Forms::Label());
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->dateTimePickerBirth = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBoxTel = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->labelBirthDay = (gcnew System::Windows::Forms::Label());
			this->labelTel = (gcnew System::Windows::Forms::Label());
			this->labelAddress = (gcnew System::Windows::Forms::Label());
			this->labelName = (gcnew System::Windows::Forms::Label());
			this->labelID = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->textBoxPassword);
			this->panel1->Controls->Add(this->labelPassword);
			this->panel1->Controls->Add(this->comboBoxAuth);
			this->panel1->Controls->Add(this->labelCharacter);
			this->panel1->Controls->Add(this->labelAuthority);
			this->panel1->Controls->Add(this->comboBoxCharacter);
			this->panel1->Controls->Add(this->comboBoxCast);
			this->panel1->Controls->Add(this->labelAttr);
			this->panel1->Controls->Add(this->labelCast);
			this->panel1->Controls->Add(this->labelGroup);
			this->panel1->Controls->Add(this->comboBoxGroup);
			this->panel1->Controls->Add(this->dateTimePickerBirth);
			this->panel1->Controls->Add(this->textBoxTel);
			this->panel1->Controls->Add(this->textBoxAddress);
			this->panel1->Controls->Add(this->textBoxName);
			this->panel1->Controls->Add(this->labelBirthDay);
			this->panel1->Controls->Add(this->labelTel);
			this->panel1->Controls->Add(this->labelAddress);
			this->panel1->Controls->Add(this->labelName);
			this->panel1->Controls->Add(this->labelID);
			this->panel1->Controls->Add(this->textBoxID);
			this->panel1->Location = System::Drawing::Point(4, 71);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(582, 352);
			this->panel1->TabIndex = 0;
			// 
			// textBoxPassword
			// 
			this->textBoxPassword->Location = System::Drawing::Point(86, 289);
			this->textBoxPassword->Name = L"textBoxPassword";
			this->textBoxPassword->Size = System::Drawing::Size(141, 19);
			this->textBoxPassword->TabIndex = 9;
			// 
			// labelPassword
			// 
			this->labelPassword->AutoSize = true;
			this->labelPassword->Location = System::Drawing::Point(20, 296);
			this->labelPassword->Name = L"labelPassword";
			this->labelPassword->Size = System::Drawing::Size(52, 12);
			this->labelPassword->TabIndex = 8;
			this->labelPassword->Text = L"�p�X���[�h";
			// 
			// comboBoxAuth
			// 
			this->comboBoxAuth->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAuth->FormattingEnabled = true;
			this->comboBoxAuth->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"�Ǘ���", L"�ҏW��", L"�{����" });
			this->comboBoxAuth->Location = System::Drawing::Point(411, 187);
			this->comboBoxAuth->Name = L"comboBoxAuth";
			this->comboBoxAuth->Size = System::Drawing::Size(121, 20);
			this->comboBoxAuth->TabIndex = 18;
			// 
			// labelCharacter
			// 
			this->labelCharacter->AutoSize = true;
			this->labelCharacter->Location = System::Drawing::Point(359, 228);
			this->labelCharacter->Name = L"labelCharacter";
			this->labelCharacter->Size = System::Drawing::Size(29, 12);
			this->labelCharacter->TabIndex = 19;
			this->labelCharacter->Text = L"�l��";
			// 
			// labelAuthority
			// 
			this->labelAuthority->AutoSize = true;
			this->labelAuthority->Location = System::Drawing::Point(359, 190);
			this->labelAuthority->Name = L"labelAuthority";
			this->labelAuthority->Size = System::Drawing::Size(29, 12);
			this->labelAuthority->TabIndex = 17;
			this->labelAuthority->Text = L"����";
			// 
			// comboBoxCharacter
			// 
			this->comboBoxCharacter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCharacter->FormattingEnabled = true;
			this->comboBoxCharacter->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"����", L"���ً���", L"�v���Ӑl��" });
			this->comboBoxCharacter->Location = System::Drawing::Point(411, 225);
			this->comboBoxCharacter->Name = L"comboBoxCharacter";
			this->comboBoxCharacter->Size = System::Drawing::Size(121, 20);
			this->comboBoxCharacter->TabIndex = 20;
			// 
			// comboBoxCast
			// 
			this->comboBoxCast->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCast->FormattingEnabled = true;
			this->comboBoxCast->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"���", L"���", L"��O", L"�c��", L"����", L"��", L"�В�" });
			this->comboBoxCast->Location = System::Drawing::Point(370, 141);
			this->comboBoxCast->Name = L"comboBoxCast";
			this->comboBoxCast->Size = System::Drawing::Size(121, 20);
			this->comboBoxCast->TabIndex = 15;
			// 
			// labelAttr
			// 
			this->labelAttr->AutoSize = true;
			this->labelAttr->Location = System::Drawing::Point(315, 190);
			this->labelAttr->Name = L"labelAttr";
			this->labelAttr->Size = System::Drawing::Size(29, 12);
			this->labelAttr->TabIndex = 16;
			this->labelAttr->Text = L"����";
			// 
			// labelCast
			// 
			this->labelCast->AutoSize = true;
			this->labelCast->Location = System::Drawing::Point(315, 144);
			this->labelCast->Name = L"labelCast";
			this->labelCast->Size = System::Drawing::Size(29, 12);
			this->labelCast->TabIndex = 14;
			this->labelCast->Text = L"��E";
			// 
			// labelGroup
			// 
			this->labelGroup->AutoSize = true;
			this->labelGroup->Location = System::Drawing::Point(315, 97);
			this->labelGroup->Name = L"labelGroup";
			this->labelGroup->Size = System::Drawing::Size(29, 12);
			this->labelGroup->TabIndex = 12;
			this->labelGroup->Text = L"����";
			// 
			// comboBoxGroup
			// 
			this->comboBoxGroup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxGroup->FormattingEnabled = true;
			this->comboBoxGroup->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"���J���O���[�v", L"���J���O���[�v", L"��O�J���O���[�v", L"�c��",
					L"����", L"��", L"�В�"
			});
			this->comboBoxGroup->Location = System::Drawing::Point(370, 94);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(121, 20);
			this->comboBoxGroup->TabIndex = 13;
			// 
			// dateTimePickerBirth
			// 
			this->dateTimePickerBirth->Location = System::Drawing::Point(361, 27);
			this->dateTimePickerBirth->Name = L"dateTimePickerBirth";
			this->dateTimePickerBirth->Size = System::Drawing::Size(200, 19);
			this->dateTimePickerBirth->TabIndex = 11;
			// 
			// textBoxTel
			// 
			this->textBoxTel->Location = System::Drawing::Point(83, 225);
			this->textBoxTel->Name = L"textBoxTel";
			this->textBoxTel->Size = System::Drawing::Size(144, 19);
			this->textBoxTel->TabIndex = 7;
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(8, 126);
			this->textBoxAddress->Multiline = true;
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(248, 76);
			this->textBoxAddress->TabIndex = 5;
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(86, 73);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(144, 19);
			this->textBoxName->TabIndex = 3;
			// 
			// labelBirthDay
			// 
			this->labelBirthDay->AutoSize = true;
			this->labelBirthDay->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelBirthDay->Location = System::Drawing::Point(277, 29);
			this->labelBirthDay->Name = L"labelBirthDay";
			this->labelBirthDay->Size = System::Drawing::Size(67, 15);
			this->labelBirthDay->TabIndex = 10;
			this->labelBirthDay->Text = L"���N����";
			// 
			// labelTel
			// 
			this->labelTel->AutoSize = true;
			this->labelTel->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelTel->Location = System::Drawing::Point(5, 228);
			this->labelTel->Name = L"labelTel";
			this->labelTel->Size = System::Drawing::Size(67, 15);
			this->labelTel->TabIndex = 6;
			this->labelTel->Text = L"�d�b�ԍ�";
			// 
			// labelAddress
			// 
			this->labelAddress->AutoSize = true;
			this->labelAddress->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelAddress->Location = System::Drawing::Point(19, 108);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(37, 15);
			this->labelAddress->TabIndex = 4;
			this->labelAddress->Text = L"�Z��";
			// 
			// labelName
			// 
			this->labelName->AutoSize = true;
			this->labelName->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelName->Location = System::Drawing::Point(22, 76);
			this->labelName->Name = L"labelName";
			this->labelName->Size = System::Drawing::Size(37, 15);
			this->labelName->TabIndex = 2;
			this->labelName->Text = L"����";
			// 
			// labelID
			// 
			this->labelID->AutoSize = true;
			this->labelID->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->labelID->Location = System::Drawing::Point(22, 29);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(21, 15);
			this->labelID->TabIndex = 0;
			this->labelID->Text = L"ID";
			// 
			// textBoxID
			// 
			this->textBoxID->Location = System::Drawing::Point(86, 29);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(144, 19);
			this->textBoxID->TabIndex = 1;
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(470, 12);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(95, 53);
			this->buttonCancel->TabIndex = 0;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(365, 12);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(95, 53);
			this->buttonOK->TabIndex = 1;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &RegistForm::buttonOK_Click);
			// 
			// RegistForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(598, 435);
			this->Controls->Add(this->buttonOK);
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->panel1);
			this->Name = L"RegistForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"RegistForm";
			this->Load += gcnew System::EventHandler(this, &RegistForm::RegistForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		Constants* registConstant;

		/*
		�֐���:setData
		�T�v:���͂���Ă���f�[�^���i�[����֐�
		����:procedureRegist procedureregist �i�[��̒l
		�ԋp�l:����
		�쐬��:10��16��(��)
		�쐬��:���c�C�V
		*/
		void setData(procedureRegist* procedureregist) {
			//���[�U�[��ID�������o�ɕۊ�
			procedureregist->userId = INT32::Parse(this->textBoxID->Text);
			//���͂��ꂽ���[�U�[�����i�[����
			procedureregist->userName = registConstant->StrToc_str(this->textBoxName->Text);
			//���͂��ꂽ�d�b�ԍ����i�[����
			procedureregist->telNo = registConstant->StrToc_str(this->textBoxTel->Text);
			//���͂��ꂽ�Z�����i�[����
			procedureregist->address = registConstant->StrToc_str(this->textBoxAddress->Text);
			//�p�X���[�h���͗��ɓ��͂��ꂽ�l������
			procedureregist->password = registConstant->StrToc_str(this->textBoxPassword->Text);

			//�I�����ꂽ���N�������擾
			DateTime date = dateTimePickerBirth->Value;
			//�N���擾
			int year = date.Year;
			//�����擾
			int month = date.Month;
			//���ɂ����擾
			int day = date.Day;

			//��ɂ܂Ƃ߂Ċi�[����
			procedureregist->birthday = year * 10000 + month * 100 + day;

			//������I�����ꂽ�C���f�b�N�X�Ŋi�[����
			procedureregist->group = comboBoxGroup->SelectedIndex;
			//��E��I�����ꂽ�C���f�b�N�X�Ŋi�[����
			procedureregist->cast = comboBoxCast->SelectedIndex;
			//�������i�[���邽�߂̕ϐ���p��
			int attr = 0;
			//������ƑI������Ă���
			if (0 <= comboBoxAuth->SelectedIndex) {
				//�O����I�΂ꂽ�C���f�b�N�X�Ԗڂ̃r�b�g�𗧂Ă�
				attr = attr | (0x01 << (15 - comboBoxAuth->SelectedIndex));
			}
			//������ƑI������Ă���
			if (0 <= comboBoxAuth->SelectedIndex) {
				//2�o�C�g�ڂ̑O����I�΂ꂽ�C���f�b�N�X�Ԗڂ̃r�b�g�𗧂Ă�
				attr = attr | (0x01 << (7 - comboBoxCharacter->SelectedIndex));
			}
			//���̑����l�������o�Ɋi�[����
			procedureregist->attr = attr;
		}

	private:
		/*
		�֐���:buttonOK_Click
		�T�v:���̓��͂�������OK�{�^�����������ꂽ�Ƃ��̃C�x���g
		����:�C�x���g�̈���
		�ԋp�l:����
		�쐬��:10��16��(��)
		�쐬��:���c�C�V
		*/
		System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
			//���݂̏��ō쐬���Ă������̊m�F
			Windows::Forms::DialogResult dr = MessageBox::Show("���݂̏��œo�^���܂��B\n��낵���ł���", "�o�^�O�m�F", MessageBoxButtons::OKCancel, MessageBoxIcon::Question);

			//�L�����Z���������ꂽ�Ƃ�
			if (dr == Windows::Forms::DialogResult::Cancel) {
				//�������s�킸�Ɏ��߂�
				return;
			}

			//�o�^�������s���N���X�̃C���X�^���X�𐶐�
			procedureRegist* procedureregist = new procedureRegist();

			try {
				//���͂��ꂽ�f�[�^�Q�������o�ɃZ�b�g����
				setData(procedureregist);
				//�������݂��邽�߂̏����̊֐������s����
				procedureregist->init();
				//�������ł����̂ŃJ�[�h���������悤�ɑ���
				MessageBox::Show("�J�[�h���������Ă�������", "�������݊J�n", MessageBoxButtons::OK, MessageBoxIcon::None);
				//�J�[�h�ւ̏������݂��J�n����
				procedureregist->registData();
				MessageBox::Show("�������݊���", "", MessageBoxButtons::OK, MessageBoxIcon::None);
				this->Close();
			}
			//��O�����������Ƃ�
			catch (std::exception& e) {
				//���b�Z�[�W�𑗏o���ė�O��`����
				MessageBox::Show(gcnew String(e.what()), "�G���[", MessageBoxButtons::OK, MessageBoxIcon::Hand);

			}
			//CLI�̗�O�����������Ƃ�
			catch (Exception^ e) {
				//�s���ȓ��͂�ʒm
				MessageBox::Show("�s���ȓ��͂�����܂��B", "", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				
			}
			//�K���s������
			finally {
				//�J�[�h���[�_�̉���������s��
				procedureregist->clear();
			}
		}


	private: 
		System::Void RegistForm_Load(System::Object^  sender, System::EventArgs^  e) {

//�f�o�b�O�R�[�h
//textBoxID->Text = "1";		
//textBoxName->Text = "���c�@�C�V";
//textBoxAddress->Text = "��ʌ�����s��R��138-26"; 
//textBoxTel->Text = "08013116165";

			this->comboBoxAuth->SelectedIndex = 2;
			this->comboBoxCast->SelectedIndex = 0;
			this->comboBoxGroup->SelectedIndex = 0;
			this->comboBoxCharacter->SelectedIndex = 0;
		}
};
}
