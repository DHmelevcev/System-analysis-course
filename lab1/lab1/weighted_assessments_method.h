#pragma once
#include <string>
#include <array>

template<size_t expert_cnt, size_t alt_cnt>
class weighted_assessments_method
{
public:
	weighted_assessments_method(
		std::array<double, expert_cnt> competencies,
		std::array<double, expert_cnt * alt_cnt> assessments
	);

	std::array<double, expert_cnt> expert_competencies;
	std::array<double, expert_cnt * alt_cnt> alternatives_assessments;

	std::array<double, alt_cnt> compute_ranking();
};