#pragma once

#include "C_Base.h"

namespace Mac {

	struct C_Position
		: public C_Base
	{
		C_Position()
			: C_Base(Component::Position)
			, m_elevation(0)
		{
		}

		~C_Position()
		{
		}

		void ReadIn(std::stringstream& l_stream)
		{
			l_stream
				>> m_position.x
				>> m_position.y
				>> m_elevation;
		}

		const sf::Vector2f& GetPosition()
		{
			return m_position;
		}

		const sf::Vector2f& GetOldPosition()
		{
			return m_positionOld;
		}

		unsigned GetElevation()
		{
			return m_elevation;
		}

		void SetPosition(float l_x, float l_y)
		{
			m_positionOld = m_position;
			m_position = sf::Vector2f(l_x, l_y);
		}


		void SetPosition(const sf::Vector2f& l_vec)
		{
			m_positionOld = m_position;
			m_position = l_vec;
		}


		void SetElevation(unsigned int l_elevation)
		{
			m_elevation = l_elevation;
		}


		void MoveBy(float l_x, float l_y)
		{
			m_positionOld = m_position;
			m_position += sf::Vector2f(l_x, l_y);
		}


		void MoveBy(const sf::Vector2f& l_vec)
		{
			m_positionOld = m_position;
			m_position += l_vec;
		}

	private:
		sf::Vector2f m_position;
		sf::Vector2f m_positionOld;
		unsigned m_elevation;
	};
}