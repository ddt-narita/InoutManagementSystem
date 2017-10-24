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
	/// EditForm �̊T�v
	/// </summary>
	public ref class EditForm : public System::Windows::Forms::Form
	{
	public:
		EditForm(void)
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
		~EditForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonOK;
	protected:
	private: System::Windows::Forms::Button^  buttonCancel;
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
	private: System::Windows::Forms::Panel^  panelInout;
	private: System::Windows::Forms::PictureBox^  pictureBoxIn;



	private: System::Windows::Forms::Label^  labelInoutYM;
	private: System::Windows::Forms::TextBox^  textBoxInoutY;
	private: System::Windows::Forms::Label^  labelInoutY;
	private: System::Windows::Forms::TextBox^  textBoxInoutM;
	private: System::Windows::Forms::Label^  labelInoutM;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirthday;
	private: System::Windows::Forms::PictureBox^  pictureBoxOut;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  labelFirstName;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;
	private: System::Windows::Forms::Label^  labelGroup;
	private: System::Windows::Forms::ComboBox^  comboBoxGroup;











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
			this->buttonOK = (gcnew System::Windows::Forms::Button());
			this->buttonCancel = (gcnew System::Windows::Forms::Button());
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
			this->panelInout = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxOut = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxIn = (gcnew System::Windows::Forms::PictureBox());
			this->labelInoutYM = (gcnew System::Windows::Forms::Label());
			this->textBoxInoutY = (gcnew System::Windows::Forms::TextBox());
			this->labelInoutY = (gcnew System::Windows::Forms::Label());
			this->textBoxInoutM = (gcnew System::Windows::Forms::TextBox());
			this->labelInoutM = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerBirthday = (gcnew System::Windows::Forms::DateTimePicker());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->labelGroup = (gcnew System::Windows::Forms::Label());
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->panelInout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIn))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonOK
			// 
			this->buttonOK->Location = System::Drawing::Point(423, 12);
			this->buttonOK->Name = L"buttonOK";
			this->buttonOK->Size = System::Drawing::Size(71, 46);
			this->buttonOK->TabIndex = 0;
			this->buttonOK->Text = L"OK";
			this->buttonOK->UseVisualStyleBackColor = true;
			this->buttonOK->Click += gcnew System::EventHandler(this, &EditForm::buttonOK_Click);
			// 
			// buttonCancel
			// 
			this->buttonCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->buttonCancel->Location = System::Drawing::Point(504, 12);
			this->buttonCancel->Name = L"buttonCancel";
			this->buttonCancel->Size = System::Drawing::Size(71, 46);
			this->buttonCancel->TabIndex = 1;
			this->buttonCancel->Text = L"Cancel";
			this->buttonCancel->UseVisualStyleBackColor = true;
			// 
			// labelID
			// 
			this->labelID->AutoSize = true;
			this->labelID->Location = System::Drawing::Point(45, 54);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(16, 12);
			this->labelID->TabIndex = 2;
			this->labelID->Text = L"ID";
			// 
			// textBoxID
			// 
			this->textBoxID->Location = System::Drawing::Point(67, 51);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(144, 19);
			this->textBoxID->TabIndex = 0;
			// 
			// labelLastName
			// 
			this->labelLastName->AutoSize = true;
			this->labelLastName->Location = System::Drawing::Point(32, 89);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(29, 12);
			this->labelLastName->TabIndex = 4;
			this->labelLastName->Text = L"�c��";
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Location = System::Drawing::Point(67, 82);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(144, 19);
			this->textBoxLastName->TabIndex = 1;
			// 
			// labelBirthday
			// 
			this->labelBirthday->AutoSize = true;
			this->labelBirthday->Location = System::Drawing::Point(9, 148);
			this->labelBirthday->Name = L"labelBirthday";
			this->labelBirthday->Size = System::Drawing::Size(53, 12);
			this->labelBirthday->TabIndex = 6;
			this->labelBirthday->Text = L"���N����";
			// 
			// textBoxTell
			// 
			this->textBoxTell->Location = System::Drawing::Point(68, 178);
			this->textBoxTell->Name = L"textBoxTell";
			this->textBoxTell->Size = System::Drawing::Size(144, 19);
			this->textBoxTell->TabIndex = 4;
			// 
			// labelTell
			// 
			this->labelTell->AutoSize = true;
			this->labelTell->Location = System::Drawing::Point(9, 181);
			this->labelTell->Name = L"labelTell";
			this->labelTell->Size = System::Drawing::Size(53, 12);
			this->labelTell->TabIndex = 11;
			this->labelTell->Text = L"�d�b�ԍ�";
			// 
			// labelAddress
			// 
			this->labelAddress->AutoSize = true;
			this->labelAddress->Location = System::Drawing::Point(258, 67);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(29, 12);
			this->labelAddress->TabIndex = 12;
			this->labelAddress->Text = L"�Z��";
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(299, 64);
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
			this->comboBoxAffili->Location = System::Drawing::Point(299, 130);
			this->comboBoxAffili->Name = L"comboBoxAffili";
			this->comboBoxAffili->Size = System::Drawing::Size(121, 20);
			this->comboBoxAffili->TabIndex = 8;
			// 
			// comboBoxCast
			// 
			this->comboBoxCast->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCast->FormattingEnabled = true;
			this->comboBoxCast->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"���Ј�", L"�p�[�g", L"����" });
			this->comboBoxCast->Location = System::Drawing::Point(301, 183);
			this->comboBoxCast->Name = L"comboBoxCast";
			this->comboBoxCast->Size = System::Drawing::Size(121, 20);
			this->comboBoxCast->TabIndex = 10;
			// 
			// comboBoxAuthority
			// 
			this->comboBoxAuthority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAuthority->FormattingEnabled = true;
			this->comboBoxAuthority->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"�{����", L"�Ǘ���" });
			this->comboBoxAuthority->Location = System::Drawing::Point(343, 209);
			this->comboBoxAuthority->Name = L"comboBoxAuthority";
			this->comboBoxAuthority->Size = System::Drawing::Size(121, 20);
			this->comboBoxAuthority->TabIndex = 11;
			// 
			// labelAffili
			// 
			this->labelAffili->AutoSize = true;
			this->labelAffili->Location = System::Drawing::Point(258, 133);
			this->labelAffili->Name = L"labelAffili";
			this->labelAffili->Size = System::Drawing::Size(29, 12);
			this->labelAffili->TabIndex = 17;
			this->labelAffili->Text = L"����";
			// 
			// labelCast
			// 
			this->labelCast->AutoSize = true;
			this->labelCast->Location = System::Drawing::Point(260, 186);
			this->labelCast->Name = L"labelCast";
			this->labelCast->Size = System::Drawing::Size(29, 12);
			this->labelCast->TabIndex = 18;
			this->labelCast->Text = L"��E";
			// 
			// labelAttr
			// 
			this->labelAttr->AutoSize = true;
			this->labelAttr->Location = System::Drawing::Point(260, 212);
			this->labelAttr->Name = L"labelAttr";
			this->labelAttr->Size = System::Drawing::Size(29, 12);
			this->labelAttr->TabIndex = 19;
			this->labelAttr->Text = L"����";
			// 
			// labelAuthority
			// 
			this->labelAuthority->AutoSize = true;
			this->labelAuthority->Location = System::Drawing::Point(299, 212);
			this->labelAuthority->Name = L"labelAuthority";
			this->labelAuthority->Size = System::Drawing::Size(29, 12);
			this->labelAuthority->TabIndex = 20;
			this->labelAuthority->Text = L"����";
			// 
			// labelCharacter
			// 
			this->labelCharacter->AutoSize = true;
			this->labelCharacter->Location = System::Drawing::Point(299, 238);
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
			this->comboBoxCharacter->Location = System::Drawing::Point(343, 235);
			this->comboBoxCharacter->Name = L"comboBoxCharacter";
			this->comboBoxCharacter->Size = System::Drawing::Size(121, 20);
			this->comboBoxCharacter->TabIndex = 12;
			// 
			// panelInout
			// 
			this->panelInout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelInout->AutoScroll = true;
			this->panelInout->Controls->Add(this->pictureBoxOut);
			this->panelInout->Controls->Add(this->pictureBoxIn);
			this->panelInout->Location = System::Drawing::Point(11, 280);
			this->panelInout->Name = L"panelInout";
			this->panelInout->Size = System::Drawing::Size(564, 218);
			this->panelInout->TabIndex = 23;
			// 
			// pictureBoxOut
			// 
			this->pictureBoxOut->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBoxOut->Location = System::Drawing::Point(271, 3);
			this->pictureBoxOut->Name = L"pictureBoxOut";
			this->pictureBoxOut->Size = System::Drawing::Size(14, 14);
			this->pictureBoxOut->TabIndex = 1;
			this->pictureBoxOut->TabStop = false;
			// 
			// pictureBoxIn
			// 
			this->pictureBoxIn->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBoxIn->Location = System::Drawing::Point(3, 3);
			this->pictureBoxIn->Name = L"pictureBoxIn";
			this->pictureBoxIn->Size = System::Drawing::Size(11, 10);
			this->pictureBoxIn->TabIndex = 0;
			this->pictureBoxIn->TabStop = false;
			this->pictureBoxIn->Visible = false;
			// 
			// labelInoutYM
			// 
			this->labelInoutYM->AutoSize = true;
			this->labelInoutYM->Location = System::Drawing::Point(6, 226);
			this->labelInoutYM->Name = L"labelInoutYM";
			this->labelInoutYM->Size = System::Drawing::Size(65, 12);
			this->labelInoutYM->TabIndex = 24;
			this->labelInoutYM->Text = L"���ފٔN��";
			// 
			// textBoxInoutY
			// 
			this->textBoxInoutY->Location = System::Drawing::Point(87, 223);
			this->textBoxInoutY->Name = L"textBoxInoutY";
			this->textBoxInoutY->Size = System::Drawing::Size(36, 19);
			this->textBoxInoutY->TabIndex = 5;
			// 
			// labelInoutY
			// 
			this->labelInoutY->AutoSize = true;
			this->labelInoutY->Location = System::Drawing::Point(129, 226);
			this->labelInoutY->Name = L"labelInoutY";
			this->labelInoutY->Size = System::Drawing::Size(17, 12);
			this->labelInoutY->TabIndex = 26;
			this->labelInoutY->Text = L"�N";
			// 
			// textBoxInoutM
			// 
			this->textBoxInoutM->Location = System::Drawing::Point(152, 223);
			this->textBoxInoutM->Name = L"textBoxInoutM";
			this->textBoxInoutM->Size = System::Drawing::Size(36, 19);
			this->textBoxInoutM->TabIndex = 6;
			// 
			// labelInoutM
			// 
			this->labelInoutM->AutoSize = true;
			this->labelInoutM->Location = System::Drawing::Point(194, 226);
			this->labelInoutM->Name = L"labelInoutM";
			this->labelInoutM->Size = System::Drawing::Size(17, 12);
			this->labelInoutM->TabIndex = 28;
			this->labelInoutM->Text = L"��";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(194, 265);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 12);
			this->label1->TabIndex = 29;
			this->label1->Text = L"(����)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 265);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 30;
			this->label2->Text = L"���t";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(85, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 12);
			this->label3->TabIndex = 31;
			this->label3->Text = L"��";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(145, 265);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 12);
			this->label4->TabIndex = 32;
			this->label4->Text = L"��";
			// 
			// dateTimePickerBirthday
			// 
			this->dateTimePickerBirthday->Location = System::Drawing::Point(68, 143);
			this->dateTimePickerBirthday->Name = L"dateTimePickerBirthday";
			this->dateTimePickerBirthday->Size = System::Drawing::Size(144, 19);
			this->dateTimePickerBirthday->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(422, 265);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 12);
			this->label5->TabIndex = 36;
			this->label5->Text = L"��";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(362, 265);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 12);
			this->label6->TabIndex = 35;
			this->label6->Text = L"��";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(297, 265);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 12);
			this->label7->TabIndex = 34;
			this->label7->Text = L"���t";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(466, 265);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 12);
			this->label8->TabIndex = 33;
			this->label8->Text = L"(�ފ�)";
			// 
			// labelFirstName
			// 
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Location = System::Drawing::Point(32, 112);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(29, 12);
			this->labelFirstName->TabIndex = 37;
			this->labelFirstName->Text = L"���O";
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Location = System::Drawing::Point(68, 109);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(144, 19);
			this->textBoxFirstName->TabIndex = 2;
			// 
			// labelGroup
			// 
			this->labelGroup->AutoSize = true;
			this->labelGroup->Location = System::Drawing::Point(244, 159);
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
			this->comboBoxGroup->Location = System::Drawing::Point(301, 156);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(121, 20);
			this->comboBoxGroup->TabIndex = 9;
			// 
			// EditForm
			// 
			this->AcceptButton = this->buttonOK;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->buttonCancel;
			this->ClientSize = System::Drawing::Size(587, 510);
			this->Controls->Add(this->comboBoxGroup);
			this->Controls->Add(this->labelGroup);
			this->Controls->Add(this->textBoxFirstName);
			this->Controls->Add(this->labelFirstName);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->dateTimePickerBirthday);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelInoutM);
			this->Controls->Add(this->textBoxInoutM);
			this->Controls->Add(this->labelInoutY);
			this->Controls->Add(this->textBoxInoutY);
			this->Controls->Add(this->labelInoutYM);
			this->Controls->Add(this->panelInout);
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
			this->Controls->Add(this->buttonCancel);
			this->Controls->Add(this->buttonOK);
			this->Name = L"EditForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"EditForm";
			this->Load += gcnew System::EventHandler(this, &EditForm::EditForm_Load);
			this->panelInout->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		DataManager* editData;
		narita::DataGridSelfMade^ gridIn;
		narita::DataGridSelfMade^ gridOut;
		int buttonFrom;

	private:
		System::Void EditForm_Load(System::Object^  sender, System::EventArgs^  e) {
			//��{���𕶎���ɕς��ė^����
			textBoxID->Text = gcnew String(editData->userId.c_str());
			//�c����n��
			textBoxLastName->Text = gcnew String(editData->userLastName.c_str());
			//���O��n��
			textBoxFirstName->Text = gcnew String(editData->userFirstName.c_str());
			
			textBoxTell->Text = gcnew String(editData->telNo.c_str());
			textBoxAddress->Text = gcnew String(editData->address.c_str());
			
			//�ǉ������R���{�{�b�N�X�̑I��l�Ƃ��Ċi�[����
			comboBoxAffili->SelectedIndex = editData->getSelectedAffli();
			comboBoxGroup->SelectedIndex = editData->getSelectedGroup();
			comboBoxCast->SelectedIndex = editData->getSelectedCast();
			comboBoxAuthority->SelectedIndex = editData->getSelectedAuth();
			comboBoxCharacter->SelectedIndex = editData->getSelectedChara();


			//�a�����̒l����N�������v�Z���Ď擾
			int year = editData->birthday / 10000;
			int month = (editData->birthday / 100) - (year * 100);
			int day = (editData->birthday) - (year * 10000) - (month * 100);
			
			//�擾�����N�����œ��t���쐻
			DateTime date(year, month, day);
			//�t�H�[���̒a�����I���̒l�Ƃ��ēn��
			dateTimePickerBirthday->Value = date;

			//���ނ̔N����n��
			textBoxInoutY->Text = editData->getInoutY().ToString();
			textBoxInoutM->Text = editData->getInoutM().ToString();

			//���ނ𗅗񂷂�\�N���X���쐬���ĕ`��Ώۂ̃s�N�`���[�{�b�N�X��n��
			gridIn = gcnew narita::DataGridSelfMade(pictureBoxIn);
			//�\�N���X�ɓ��ނ̔z���n���ăf�[�^�쐻
			gridIn->cell->applyVecData(editData->inTime);

			//�s������ނ̔N���̔z��̒�����
			gridIn->rowCount = editData->inTime.size();
			//�񐔂���ށA�N�A���A����4�ɐݒ�
			gridIn->colCount = 3;
			//�S�̂�`�悷��
			gridIn->Paint();
			//
			pictureBoxIn->Visible = true;

			//���ނ𗅗񂷂�\�N���X���쐬���ĕ`��Ώۂ̃s�N�`���[�{�b�N�X��n��
			gridOut = gcnew narita::DataGridSelfMade(pictureBoxOut);
			//�\�N���X�ɓ��ނ̔z���n���ăf�[�^�쐻
			gridOut->cell->applyVecData(editData->outTime);

			//�s������ނ̔N���̔z��̒�����
			gridOut->rowCount = editData->outTime.size();
			//�񐔂���ށA�N�A���A����4�ɐݒ�
			gridOut->colCount = 3;
			//�S�̂�`�悷��
			gridOut->Paint();
			//
			pictureBoxOut->Visible = true;

			

			//���\���{�^������̂��̂Ȃ�
			if (buttonFrom == 1) {
				//�t�H�[���̊e����ǂݍ��ݐ�p�ɂ���
				setReadOnly();
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
			textBoxFirstName->ReadOnly = true;		//���O
			textBoxLastName->ReadOnly = true;
			textBoxAddress->ReadOnly = true;	//�Z��
			textBoxTell->ReadOnly = true;		//�d�b
			textBoxInoutY->ReadOnly = true;		//�N
			textBoxInoutM->ReadOnly = true;		//��

			//�R���{�{�b�N�X���h���b�v�_�E���ł��Ȃ�����
			comboBoxGroup->Enabled = false;		//����
			comboBoxAffili->Enabled = false;
			comboBoxCast->Enabled = false;		//��E
			comboBoxAuthority->Enabled = false;	//����
			comboBoxCharacter->Enabled = false;	//�l��

			//���t�I���R���g���[�����I���ł��Ȃ�����
			dateTimePickerBirthday->Enabled = false;
		}

private:
	/*
	�֐���:buttonOK_Click
	�T�v:OK�{�^��������
	����:�C�x���g
	�ԋp�l:�Ȃ�
	�쐬��:10��18��(��)
	�쐬��:���c�C�V
	*/
	System::Void buttonOK_Click(System::Object^  sender, System::EventArgs^  e) {
		//�t�H�[�������
		this->Close();
	}
};
}
