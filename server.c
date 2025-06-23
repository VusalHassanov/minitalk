/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:29:05 by vhasanov          #+#    #+#             */
/*   Updated: 2025/05/21 15:29:05 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void handle_signal(int sig){
  static unsigned char c;
  static int bit_index = 0;

  if(sig == SIGUSR2)
    c |= (1 << (7 - bit_index));
    bit_index++;

    if(bit_index == 8){
      write(1, &c, 1);
      bit_index = 0;
      c = 0;
    }
}

int main(void){
  pid_t pid;
  pid = getpid();

  signal(SIGUSR, handle_signal);
  signal(SIGUSR, handle_signal);

  while(1)
    pause();
  return 0;
}
