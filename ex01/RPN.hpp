/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:33:06 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/26 11:35:44 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN
{
	public:
		static int	evaluate(const std::string &input);

	private:
		RPN();
		RPN( RPN const & src );
		~RPN();
		RPN &		operator=( RPN const & rhs );

};

#endif /* ************************************************************* RPN_H */