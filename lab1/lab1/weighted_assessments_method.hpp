#include "weighted_assessments_method.h"
#include <numeric>

template<size_t expert_cnt, size_t alt_cnt>
weighted_assessments_method<expert_cnt, alt_cnt>::
	weighted_assessments_method(
		std::array<double, expert_cnt> competencies,
		std::array<double, expert_cnt * alt_cnt> assessments
	) : expert_competencies(competencies),
		alternatives_assessments(assessments) {}

template<size_t expert_cnt, size_t alt_cnt>
std::array<double, alt_cnt> weighted_assessments_method<expert_cnt, alt_cnt>::
	compute_ranking()
{
	const double expert_competencies_summ = std::accumulate(expert_competencies.begin(), expert_competencies.end(), 0.);

	std::array<double, expert_cnt> relative_competencies = expert_competencies;
	for (auto& rc : relative_competencies)
		rc /= expert_competencies_summ;

	std::array<double, alt_cnt> result_weights{};
	for (size_t i = 0; i < expert_cnt; ++i)
		for (size_t j = 0; j < alt_cnt; ++j)
			result_weights[j] += alternatives_assessments[i * alt_cnt + j] * relative_competencies[i];

		return result_weights;
}