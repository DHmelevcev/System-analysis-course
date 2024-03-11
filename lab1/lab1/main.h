#pragma once
#include "weighted_assessments_method.hpp"

namespace lab1
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class main : public System::Windows::Forms::Form
	{
	public:
		main(void)
		{
			InitializeComponent();

			create_collums();
			fill_rows();
		}

	protected:
		~main()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^ dataGridView1;

	protected:
		void create_collums()
		{
			dataGridView1->Columns->Add("experts", "Компетентность Экспертов");
			dataGridView1->Columns->Add("z1", "Строительство парка отдыха с аттракционами для детей");
			dataGridView1->Columns->Add("z2", "Благоустройство пруда");
			dataGridView1->Columns->Add("z3", "Сохранение лесного массива");
			dataGridView1->Columns->Add("z4", "Строительство скоростной платной магистрали");
		}

		void fill_rows()
		{
			const size_t expert_cnt = 3;
			const size_t alt_cnt = 4;

			weighted_assessments_method<expert_cnt, alt_cnt> assessments(
				{
					7, 8, 10,
				}, {
					0.3, 0.5, 0.1, 0.1,
					0.4, 0.2, 0.3, 0.1,
					0.2, 0.1, 0.1, 0.6,
				});

			auto result = assessments.compute_ranking();

			for (size_t i = 0; i < expert_cnt; ++i)
				dataGridView1->Rows->Add(
					assessments.expert_competencies[i],
					assessments.alternatives_assessments[i * alt_cnt + 0],
					assessments.alternatives_assessments[i * alt_cnt + 1],
					assessments.alternatives_assessments[i * alt_cnt + 2],
					assessments.alternatives_assessments[i * alt_cnt + 3]
					);

			dataGridView1->Rows->Add("Взвешенные оценки", result[0], result[1], result[2], result[3]);
		}

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Control;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(1154, 820);
			this->dataGridView1->TabIndex = 0;
			// 
			// main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1178, 844);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"main";
			this->Text = L"МЕТОД ВЗВЕШЕННЫХ ЭКСПЕРТНЫХ ОЦЕНОК";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
