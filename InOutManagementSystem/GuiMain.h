#pragma once

#include "Constants.h"
#include "procedureInOut.h"
#include "RegistForm.h"
#include "EditForm.h"
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
	private: System::Windows::Forms::Button^  buttonIn;
	private: System::Windows::Forms::Button^  buttonOut;
	private: System::Windows::Forms::Button^  buttonRegister;
	private: System::Windows::Forms::Label^  labelIn;

	private: System::Windows::Forms::Label^  labelOut;


	private: System::Windows::Forms::Button^  buttonDataView;
	private: System::Windows::Forms::Button^  buttonEdit;
	private: System::Windows::Forms::Label^  labelCautionNeed;
	private: System::Windows::Forms::ComboBox^  comboBoxGroup;
	private: System::Windows::Forms::Label^  labelGroup;
	private: System::Windows::Forms::TextBox^  textBoxFirstName;
	private: System::Windows::Forms::Label^  labelFirstName;




	private: System::Windows::Forms::DateTimePicker^  dateTimePickerBirthday;




	private: System::Windows::Forms::Label^  labelInoutM;
	private: System::Windows::Forms::TextBox^  textBoxInoutM;
	private: System::Windows::Forms::Label^  labelInoutY;
	private: System::Windows::Forms::TextBox^  textBoxInoutY;
	private: System::Windows::Forms::Label^  labelInoutYM;




	private: System::Windows::Forms::Label^  labelCharacter;
	private: System::Windows::Forms::Label^  labelAuthority;
	private: System::Windows::Forms::Label^  labelAttr;
	private: System::Windows::Forms::Label^  labelCast;
	private: System::Windows::Forms::Label^  labelAffili;
	private: System::Windows::Forms::ComboBox^  comboBoxAuthority;
	private: System::Windows::Forms::ComboBox^  comboBoxCast;
	private: System::Windows::Forms::ComboBox^  comboBoxAffili;
	private: System::Windows::Forms::TextBox^  textBoxAddress;
	private: System::Windows::Forms::Label^  labelAddress;
	private: System::Windows::Forms::Label^  labelTell;
	private: System::Windows::Forms::TextBox^  textBoxTell;
	private: System::Windows::Forms::Label^  labelBirthday;
	private: System::Windows::Forms::TextBox^  textBoxLastName;
	private: System::Windows::Forms::Label^  labelLastName;
	private: System::Windows::Forms::TextBox^  textBoxID;
	private: System::Windows::Forms::Label^  labelID;
	private: System::Windows::Forms::Panel^  paneldata;
	private: System::Windows::Forms::ComboBox^  comboBoxCharacter;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panelInout;
	private: System::Windows::Forms::PictureBox^  pictureBoxOut;
	private: System::Windows::Forms::PictureBox^  pictureBoxIn;





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
			this->comboBoxGroup = (gcnew System::Windows::Forms::ComboBox());
			this->labelGroup = (gcnew System::Windows::Forms::Label());
			this->textBoxFirstName = (gcnew System::Windows::Forms::TextBox());
			this->labelFirstName = (gcnew System::Windows::Forms::Label());
			this->dateTimePickerBirthday = (gcnew System::Windows::Forms::DateTimePicker());
			this->labelInoutM = (gcnew System::Windows::Forms::Label());
			this->textBoxInoutM = (gcnew System::Windows::Forms::TextBox());
			this->labelInoutY = (gcnew System::Windows::Forms::Label());
			this->textBoxInoutY = (gcnew System::Windows::Forms::TextBox());
			this->labelInoutYM = (gcnew System::Windows::Forms::Label());
			this->labelCharacter = (gcnew System::Windows::Forms::Label());
			this->labelAuthority = (gcnew System::Windows::Forms::Label());
			this->labelAttr = (gcnew System::Windows::Forms::Label());
			this->labelCast = (gcnew System::Windows::Forms::Label());
			this->labelAffili = (gcnew System::Windows::Forms::Label());
			this->comboBoxAuthority = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxCast = (gcnew System::Windows::Forms::ComboBox());
			this->comboBoxAffili = (gcnew System::Windows::Forms::ComboBox());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->labelAddress = (gcnew System::Windows::Forms::Label());
			this->labelTell = (gcnew System::Windows::Forms::Label());
			this->textBoxTell = (gcnew System::Windows::Forms::TextBox());
			this->labelBirthday = (gcnew System::Windows::Forms::Label());
			this->textBoxLastName = (gcnew System::Windows::Forms::TextBox());
			this->labelLastName = (gcnew System::Windows::Forms::Label());
			this->textBoxID = (gcnew System::Windows::Forms::TextBox());
			this->labelID = (gcnew System::Windows::Forms::Label());
			this->paneldata = (gcnew System::Windows::Forms::Panel());
			this->comboBoxCharacter = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelInout = (gcnew System::Windows::Forms::Panel());
			this->pictureBoxOut = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxIn = (gcnew System::Windows::Forms::PictureBox());
			this->paneldata->SuspendLayout();
			this->panelInout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOut))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIn))->BeginInit();
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
			this->labelIn->Location = System::Drawing::Point(352, 89);
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
			this->labelOut->Location = System::Drawing::Point(352, 89);
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
			this->buttonDataView->Visible = false;
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
			this->labelCautionNeed->Location = System::Drawing::Point(27, 96);
			this->labelCautionNeed->Name = L"labelCautionNeed";
			this->labelCautionNeed->Size = System::Drawing::Size(308, 48);
			this->labelCautionNeed->TabIndex = 8;
			this->labelCautionNeed->Text = L"�I�v���Ӑl��";
			this->labelCautionNeed->Visible = false;
			// 
			// comboBoxGroup
			// 
			this->comboBoxGroup->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxGroup->FormattingEnabled = true;
			this->comboBoxGroup->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"���O���[�v", L"���O���[�v", L"��O�O���[�v" });
			this->comboBoxGroup->Location = System::Drawing::Point(289, 100);
			this->comboBoxGroup->Name = L"comboBoxGroup";
			this->comboBoxGroup->Size = System::Drawing::Size(121, 20);
			this->comboBoxGroup->TabIndex = 52;
			// 
			// labelGroup
			// 
			this->labelGroup->AutoSize = true;
			this->labelGroup->Location = System::Drawing::Point(232, 103);
			this->labelGroup->Name = L"labelGroup";
			this->labelGroup->Size = System::Drawing::Size(43, 12);
			this->labelGroup->TabIndex = 76;
			this->labelGroup->Text = L"�O���[�v";
			// 
			// textBoxFirstName
			// 
			this->textBoxFirstName->Location = System::Drawing::Point(66, 61);
			this->textBoxFirstName->Name = L"textBoxFirstName";
			this->textBoxFirstName->Size = System::Drawing::Size(144, 19);
			this->textBoxFirstName->TabIndex = 43;
			// 
			// labelFirstName
			// 
			this->labelFirstName->AutoSize = true;
			this->labelFirstName->Location = System::Drawing::Point(30, 64);
			this->labelFirstName->Name = L"labelFirstName";
			this->labelFirstName->Size = System::Drawing::Size(29, 12);
			this->labelFirstName->TabIndex = 75;
			this->labelFirstName->Text = L"���O";
			// 
			// dateTimePickerBirthday
			// 
			this->dateTimePickerBirthday->Location = System::Drawing::Point(66, 95);
			this->dateTimePickerBirthday->Name = L"dateTimePickerBirthday";
			this->dateTimePickerBirthday->Size = System::Drawing::Size(144, 19);
			this->dateTimePickerBirthday->TabIndex = 44;
			// 
			// labelInoutM
			// 
			this->labelInoutM->AutoSize = true;
			this->labelInoutM->Location = System::Drawing::Point(192, 178);
			this->labelInoutM->Name = L"labelInoutM";
			this->labelInoutM->Size = System::Drawing::Size(17, 12);
			this->labelInoutM->TabIndex = 66;
			this->labelInoutM->Text = L"��";
			// 
			// textBoxInoutM
			// 
			this->textBoxInoutM->Location = System::Drawing::Point(150, 175);
			this->textBoxInoutM->Name = L"textBoxInoutM";
			this->textBoxInoutM->Size = System::Drawing::Size(36, 19);
			this->textBoxInoutM->TabIndex = 49;
			// 
			// labelInoutY
			// 
			this->labelInoutY->AutoSize = true;
			this->labelInoutY->Location = System::Drawing::Point(127, 178);
			this->labelInoutY->Name = L"labelInoutY";
			this->labelInoutY->Size = System::Drawing::Size(17, 12);
			this->labelInoutY->TabIndex = 65;
			this->labelInoutY->Text = L"�N";
			// 
			// textBoxInoutY
			// 
			this->textBoxInoutY->Location = System::Drawing::Point(85, 175);
			this->textBoxInoutY->Name = L"textBoxInoutY";
			this->textBoxInoutY->Size = System::Drawing::Size(36, 19);
			this->textBoxInoutY->TabIndex = 47;
			// 
			// labelInoutYM
			// 
			this->labelInoutYM->AutoSize = true;
			this->labelInoutYM->Location = System::Drawing::Point(4, 178);
			this->labelInoutYM->Name = L"labelInoutYM";
			this->labelInoutYM->Size = System::Drawing::Size(65, 12);
			this->labelInoutYM->TabIndex = 64;
			this->labelInoutYM->Text = L"���ފٔN��";
			// 
			// labelCharacter
			// 
			this->labelCharacter->AutoSize = true;
			this->labelCharacter->Location = System::Drawing::Point(287, 182);
			this->labelCharacter->Name = L"labelCharacter";
			this->labelCharacter->Size = System::Drawing::Size(29, 12);
			this->labelCharacter->TabIndex = 62;
			this->labelCharacter->Text = L"�l��";
			// 
			// labelAuthority
			// 
			this->labelAuthority->AutoSize = true;
			this->labelAuthority->Location = System::Drawing::Point(287, 156);
			this->labelAuthority->Name = L"labelAuthority";
			this->labelAuthority->Size = System::Drawing::Size(29, 12);
			this->labelAuthority->TabIndex = 61;
			this->labelAuthority->Text = L"����";
			// 
			// labelAttr
			// 
			this->labelAttr->AutoSize = true;
			this->labelAttr->Location = System::Drawing::Point(248, 156);
			this->labelAttr->Name = L"labelAttr";
			this->labelAttr->Size = System::Drawing::Size(29, 12);
			this->labelAttr->TabIndex = 60;
			this->labelAttr->Text = L"����";
			// 
			// labelCast
			// 
			this->labelCast->AutoSize = true;
			this->labelCast->Location = System::Drawing::Point(248, 130);
			this->labelCast->Name = L"labelCast";
			this->labelCast->Size = System::Drawing::Size(29, 12);
			this->labelCast->TabIndex = 59;
			this->labelCast->Text = L"��E";
			// 
			// labelAffili
			// 
			this->labelAffili->AutoSize = true;
			this->labelAffili->Location = System::Drawing::Point(246, 77);
			this->labelAffili->Name = L"labelAffili";
			this->labelAffili->Size = System::Drawing::Size(29, 12);
			this->labelAffili->TabIndex = 58;
			this->labelAffili->Text = L"����";
			// 
			// comboBoxAuthority
			// 
			this->comboBoxAuthority->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAuthority->FormattingEnabled = true;
			this->comboBoxAuthority->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"�{����", L"�Ǘ���" });
			this->comboBoxAuthority->Location = System::Drawing::Point(331, 153);
			this->comboBoxAuthority->Name = L"comboBoxAuthority";
			this->comboBoxAuthority->Size = System::Drawing::Size(121, 20);
			this->comboBoxAuthority->TabIndex = 55;
			// 
			// comboBoxCast
			// 
			this->comboBoxCast->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCast->FormattingEnabled = true;
			this->comboBoxCast->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"���Ј�", L"�p�[�g", L"����" });
			this->comboBoxCast->Location = System::Drawing::Point(289, 127);
			this->comboBoxCast->Name = L"comboBoxCast";
			this->comboBoxCast->Size = System::Drawing::Size(121, 20);
			this->comboBoxCast->TabIndex = 53;
			// 
			// comboBoxAffili
			// 
			this->comboBoxAffili->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAffili->FormattingEnabled = true;
			this->comboBoxAffili->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"�c��", L"����", L"�J��" });
			this->comboBoxAffili->Location = System::Drawing::Point(287, 74);
			this->comboBoxAffili->Name = L"comboBoxAffili";
			this->comboBoxAffili->Size = System::Drawing::Size(121, 20);
			this->comboBoxAffili->TabIndex = 51;
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(287, 8);
			this->textBoxAddress->Multiline = true;
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(276, 60);
			this->textBoxAddress->TabIndex = 50;
			// 
			// labelAddress
			// 
			this->labelAddress->AutoSize = true;
			this->labelAddress->Location = System::Drawing::Point(246, 11);
			this->labelAddress->Name = L"labelAddress";
			this->labelAddress->Size = System::Drawing::Size(29, 12);
			this->labelAddress->TabIndex = 56;
			this->labelAddress->Text = L"�Z��";
			// 
			// labelTell
			// 
			this->labelTell->AutoSize = true;
			this->labelTell->Location = System::Drawing::Point(7, 133);
			this->labelTell->Name = L"labelTell";
			this->labelTell->Size = System::Drawing::Size(53, 12);
			this->labelTell->TabIndex = 54;
			this->labelTell->Text = L"�d�b�ԍ�";
			// 
			// textBoxTell
			// 
			this->textBoxTell->Location = System::Drawing::Point(66, 130);
			this->textBoxTell->Name = L"textBoxTell";
			this->textBoxTell->Size = System::Drawing::Size(144, 19);
			this->textBoxTell->TabIndex = 46;
			// 
			// labelBirthday
			// 
			this->labelBirthday->AutoSize = true;
			this->labelBirthday->Location = System::Drawing::Point(7, 100);
			this->labelBirthday->Name = L"labelBirthday";
			this->labelBirthday->Size = System::Drawing::Size(53, 12);
			this->labelBirthday->TabIndex = 48;
			this->labelBirthday->Text = L"���N����";
			// 
			// textBoxLastName
			// 
			this->textBoxLastName->Location = System::Drawing::Point(65, 34);
			this->textBoxLastName->Name = L"textBoxLastName";
			this->textBoxLastName->Size = System::Drawing::Size(144, 19);
			this->textBoxLastName->TabIndex = 41;
			// 
			// labelLastName
			// 
			this->labelLastName->AutoSize = true;
			this->labelLastName->Location = System::Drawing::Point(30, 41);
			this->labelLastName->Name = L"labelLastName";
			this->labelLastName->Size = System::Drawing::Size(29, 12);
			this->labelLastName->TabIndex = 45;
			this->labelLastName->Text = L"�c��";
			// 
			// textBoxID
			// 
			this->textBoxID->Location = System::Drawing::Point(65, 3);
			this->textBoxID->Name = L"textBoxID";
			this->textBoxID->Size = System::Drawing::Size(144, 19);
			this->textBoxID->TabIndex = 40;
			// 
			// labelID
			// 
			this->labelID->AutoSize = true;
			this->labelID->Location = System::Drawing::Point(43, 6);
			this->labelID->Name = L"labelID";
			this->labelID->Size = System::Drawing::Size(16, 12);
			this->labelID->TabIndex = 42;
			this->labelID->Text = L"ID";
			// 
			// paneldata
			// 
			this->paneldata->Controls->Add(this->textBoxID);
			this->paneldata->Controls->Add(this->comboBoxGroup);
			this->paneldata->Controls->Add(this->labelGroup);
			this->paneldata->Controls->Add(this->labelID);
			this->paneldata->Controls->Add(this->labelLastName);
			this->paneldata->Controls->Add(this->textBoxFirstName);
			this->paneldata->Controls->Add(this->textBoxLastName);
			this->paneldata->Controls->Add(this->labelFirstName);
			this->paneldata->Controls->Add(this->labelBirthday);
			this->paneldata->Controls->Add(this->textBoxTell);
			this->paneldata->Controls->Add(this->comboBoxCharacter);
			this->paneldata->Controls->Add(this->labelCharacter);
			this->paneldata->Controls->Add(this->labelTell);
			this->paneldata->Controls->Add(this->labelInoutYM);
			this->paneldata->Controls->Add(this->textBoxInoutY);
			this->paneldata->Controls->Add(this->dateTimePickerBirthday);
			this->paneldata->Controls->Add(this->labelInoutY);
			this->paneldata->Controls->Add(this->labelAuthority);
			this->paneldata->Controls->Add(this->textBoxInoutM);
			this->paneldata->Controls->Add(this->labelAttr);
			this->paneldata->Controls->Add(this->labelInoutM);
			this->paneldata->Controls->Add(this->labelCast);
			this->paneldata->Controls->Add(this->labelAddress);
			this->paneldata->Controls->Add(this->labelAffili);
			this->paneldata->Controls->Add(this->textBoxAddress);
			this->paneldata->Controls->Add(this->comboBoxAuthority);
			this->paneldata->Controls->Add(this->comboBoxAffili);
			this->paneldata->Controls->Add(this->comboBoxCast);
			this->paneldata->Enabled = false;
			this->paneldata->Location = System::Drawing::Point(12, 147);
			this->paneldata->Name = L"paneldata";
			this->paneldata->Size = System::Drawing::Size(668, 206);
			this->paneldata->TabIndex = 77;
			// 
			// comboBoxCharacter
			// 
			this->comboBoxCharacter->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxCharacter->FormattingEnabled = true;
			this->comboBoxCharacter->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"����", L"���ً���", L"�v���Ӑl��" });
			this->comboBoxCharacter->Location = System::Drawing::Point(331, 179);
			this->comboBoxCharacter->Name = L"comboBoxCharacter";
			this->comboBoxCharacter->Size = System::Drawing::Size(121, 20);
			this->comboBoxCharacter->TabIndex = 57;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(423, 356);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(17, 12);
			this->label5->TabIndex = 86;
			this->label5->Text = L"��";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(363, 356);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 12);
			this->label6->TabIndex = 85;
			this->label6->Text = L"��";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(298, 356);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(29, 12);
			this->label7->TabIndex = 84;
			this->label7->Text = L"���t";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(467, 356);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(37, 12);
			this->label8->TabIndex = 83;
			this->label8->Text = L"(�ފ�)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(146, 356);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 12);
			this->label4->TabIndex = 82;
			this->label4->Text = L"��";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(86, 356);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 12);
			this->label3->TabIndex = 81;
			this->label3->Text = L"��";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(21, 356);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 12);
			this->label2->TabIndex = 80;
			this->label2->Text = L"���t";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(195, 356);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(37, 12);
			this->label1->TabIndex = 79;
			this->label1->Text = L"(����)";
			// 
			// panelInout
			// 
			this->panelInout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panelInout->AutoScroll = true;
			this->panelInout->Controls->Add(this->pictureBoxOut);
			this->panelInout->Controls->Add(this->pictureBoxIn);
			this->panelInout->Location = System::Drawing::Point(12, 371);
			this->panelInout->Name = L"panelInout";
			this->panelInout->Size = System::Drawing::Size(642, 213);
			this->panelInout->TabIndex = 78;
			// 
			// pictureBoxOut
			// 
			this->pictureBoxOut->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBoxOut->Location = System::Drawing::Point(271, 3);
			this->pictureBoxOut->Name = L"pictureBoxOut";
			this->pictureBoxOut->Size = System::Drawing::Size(14, 14);
			this->pictureBoxOut->TabIndex = 1;
			this->pictureBoxOut->TabStop = false;
			this->pictureBoxOut->Visible = false;
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
			// GuiMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(695, 596);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panelInout);
			this->Controls->Add(this->paneldata);
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
			this->paneldata->ResumeLayout(false);
			this->paneldata->PerformLayout();
			this->panelInout->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxOut))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxIn))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		procedureInOut* procedureInout;
		narita::DataGridSelfMade^ gridIn;
		narita::DataGridSelfMade^ gridOut;


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
			int character = procedureInout->chara;

			if (character == constants.noInout) {
				throw std::exception("");
			}
			else if (character == constants.cautionNeed) {
				labelCautionNeed->Visible = true;
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
				inoutView(procedureInout);
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
				//�J�[�h�̃f�[�^���t�@�C������擾����
				cardData->readCardData();
				cardData->checkId();
				
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
			passform->id = gcnew String(cardData->userId.c_str());
			passform->name = gcnew String(cardData->userLastName.c_str());
			passform->password = gcnew String(cardData->password.c_str());
			passform->ShowDialog();

			//
			if (!passform->Judge) {
				//
				throw std::exception("�\�����������f����܂����B");
			}
		}


		void inoutView(DataManager* data) {

			//��{���𕶎���ɕς��ė^����
			textBoxID->Text = gcnew String(data->userId.c_str());
			//�c����n��
			textBoxLastName->Text = gcnew String(data->userLastName.c_str());
			//���O��n��
			textBoxFirstName->Text = gcnew String(data->userFirstName.c_str());

			textBoxTell->Text = gcnew String(data->telNo.c_str());
			textBoxAddress->Text = gcnew String(data->address.c_str());

			//�ǉ������R���{�{�b�N�X�̑I��l�Ƃ��Ċi�[����
			comboBoxAffili->SelectedIndex = data->getSelectedAffli();
			comboBoxGroup->SelectedIndex = data->getSelectedGroup();
			comboBoxCast->SelectedIndex = data->getSelectedCast();
			comboBoxAuthority->SelectedIndex = data->getSelectedAuth();
			comboBoxCharacter->SelectedIndex = data->getSelectedChara();


			//�a�����̒l����N�������v�Z���Ď擾
			int year = data->birthday / 10000;
			int month = (data->birthday / 100) - (year * 100);
			int day = (data->birthday) - (year * 10000) - (month * 100);

			//�擾�����N�����œ��t���쐻
			DateTime date(year, month, day);
			//�t�H�[���̒a�����I���̒l�Ƃ��ēn��
			dateTimePickerBirthday->Value = date;

			//���ނ̔N����n��
			textBoxInoutY->Text = data->getInoutY().ToString();
			textBoxInoutM->Text = data->getInoutM().ToString();

			//���ނ𗅗񂷂�\�N���X���쐬���ĕ`��Ώۂ̃s�N�`���[�{�b�N�X��n��
			gridIn = gcnew narita::DataGridSelfMade(pictureBoxIn);
			//�\�N���X�ɓ��ނ̔z���n���ăf�[�^�쐻
			gridIn->cell->applyVecData(data->inTime);

			//�s������ނ̔N���̔z��̒�����
			gridIn->rowCount = data->inTime.size();
			//�񐔂���ށA�N�A���A����4�ɐݒ�
			gridIn->colCount = 3;
			//�S�̂�`�悷��
			gridIn->Paint();
			//
			pictureBoxIn->Visible = true;

			//���ނ𗅗񂷂�\�N���X���쐬���ĕ`��Ώۂ̃s�N�`���[�{�b�N�X��n��
			gridOut = gcnew narita::DataGridSelfMade(pictureBoxOut);
			//�\�N���X�ɓ��ނ̔z���n���ăf�[�^�쐻
			gridOut->cell->applyVecData(data->outTime);

			//�s������ނ̔N���̔z��̒�����
			gridOut->rowCount = data->outTime.size();
			//�񐔂���ށA�N�A���A����4�ɐݒ�
			gridOut->colCount = 3;
			//�S�̂�`�悷��
			gridOut->Paint();
			//
			pictureBoxOut->Visible = true;

			paneldata->Enabled = false;
		}

	};
}
