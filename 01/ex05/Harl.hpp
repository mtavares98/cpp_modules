/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtavares <mtavares@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:04:58 by mtavares          #+#    #+#             */
/*   Updated: 2022/12/24 15:27:03 by mtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

#include <iostream>


class Harl
{
	typedef	struct s_func
	{
		std::string	name;
		void	(Harl::*action)(void);
	}	t_func;
	private:
		t_func	func[4];
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};


#endif
