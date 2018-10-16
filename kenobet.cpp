#include "kenobet.h" 

bool KenoBet::add_number ( number_type spot_ ){
	for (number_type i = 0; i < m_spots.size(); ++i)
	{
		if(m_spots[i] == spot_){
			std::cout << "Number " << spot_ <<" already in the bet" << std::endl;
			return false;
		}
	}
	std::cout << "Number " << spot_ <<" added to the bet" << std::endl;
	m_spots.push_back(spot_);
	return true;
}


set_of_numbers_type KenoBet::get_spots ( void ){
	return m_spots;
}

bool KenoBet::set_wage ( cash_type wage_ ){
	if(wage_ < 0){
		return false;
	}
	else{
		m_wage = wage_;
		return true;
	}

}

cash_type KenoBet::get_wage ( void ) const {
	return m_wage;
}

void KenoBet::reset ( void ){
	m_spots.clear();
	std::cout << "All bets were cleared!" << std::endl;
}

size_t KenoBet::size ( void ) const{
	return m_spots.size();
}