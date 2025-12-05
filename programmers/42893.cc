/*
https://school.programmers.co.kr/learn/courses/30/lessons/42893
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <vector>

using namespace std;

map<string, int> m_idx;		 // site index mapping table
map<string, double> m_score; // site score
vector<string> v_site;
int solution(string word, vector<string> pages) {
	m_idx = map<string, int>();
	m_score = map<string, double>();
	v_site = vector<string>();
	regex re_url(
			R"delim(<head>[\s\S]*<meta\sproperty="og:url"\scontent="https://([^"]+)"[\s\S]*</head>)delim",
			regex_constants::icase);
	regex re_external(R"DELIM(<a\shref="https://([^"]+)">)DELIM",
					  regex_constants::icase);
	regex re_tag("<[^>]+>|[0-9]");
	string reword = "\\b" + word + "\\b";
	regex re_word(reword, regex_constants::icase);
	int answer = 0;

	for (int i = 0; i < pages.size(); i++) {
		string page = pages[i];
		smatch sm_url;
		regex_search(page, sm_url, re_url);
		string cur = sm_url[1].str();
		m_idx[cur] = i;
		v_site.push_back(cur);
		if (m_score.count(cur) == 0)
			m_score[cur] = 0.0;

		int word_count = 0;
		string replaced = regex_replace(page, re_tag, " ");
		for (sregex_iterator it(replaced.begin(), replaced.end(), re_word), end;
			 it != end; it++) {
			word_count++;
		}
		m_score[cur] += word_count;

		vector<string> exts;
		for (sregex_iterator it(page.begin(), page.end(), re_external), end;
			 it != end; it++) {
			smatch ex = *it;
			exts.push_back(ex[1].str());
		}
		cout << "ext size()" << exts.size() << endl;
		for (auto e : exts) {
			if (!m_score.count(e))
				m_score[e] = 0.0;
			m_score[e] += (double)word_count / exts.size();
		}
	}

	stable_sort(v_site.begin(), v_site.end(), [&](string a, string b) {
		if (m_score[a] == m_score[b])
			return false;
		return m_score[a] > m_score[b];
	});
	for (auto e : m_score)
		cout << e.first << " : " << e.second << "점" << endl;

	return m_idx[v_site[0]];
}
