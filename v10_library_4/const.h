/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem5491 <oem5491@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:56:31 by omayer            #+#    #+#             */
/*   Updated: 2026/03/22 15:19:10 by oem5491          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_H
# define CONST_H

# define FALSE 0
# define TRUE 1
# define NONE 0
# define EQUAL 0
# define ERROR -1
# define EXIT -2
# define ENULL -3
# define ENFOUND -5
# define ELIMIT -6
# define EEXT -15
# define SUCCESS 0
# define SLINESIZE 4124
# define ENVSIZE 61440
# define HISSIZE 41240
# define SAFE 16
# define CACHE PIPE_BUF
# define MAIN_PID_INIT -1
# define MAIN_PID 1
# define PROCESS_PID 0
# define AD -1
# define INIT -2
# define SEARCH_MIN 1
# define EMPTY_DELIMITER "#ED#"
# define EMPTY_LINE "#EL#"
# define EMPTY_HERE "#EH#"
# define HEADER_LINE "#HL#"
# define HERE_FILE "/tmp/msh_cmds"
# define SBINF 1
# define SBINNF -5
# define INLINE_LIST 5
# define FILE_LIMIT 75
# define CLF_ORIG 35385

# define DISPLAY_BUFF 266240
# define MIN_MEMORY 798720
# define ERASE 2
# define ERASE1 3
# define ERASE2 4
# define IDX_BLUE 1
# define IDX_WHITE 2
# define IDX_GREY 3
# define IDX_VOID 15
# define COL_BLUE "\033[1;34m"
# define COL_WHITE "\033[1;0m"
# define COL_GREY "\033[1;90m"
# define SCR_OFFSET 1

# define CMD_ECHO "echo"
# define CMD_CD "cd"
# define CMD_PWD "pwd"
# define CMD_EXPORT "export"
# define CMD_UNSET "unset"
# define CMD_ENV "env"
# define CMD_EXIT "exit"

# define C_MODE "mSH_MODE"
# define C_MAIN "MAIN"
# define C_PS "PS"
# define C_PSD "PSD"
# define C_EXEC "EXEC"

# define ERR_CTRLC 130

# define E_MAINPID "mSH_MAINPID"
# define L_SHLES "mSH_LES"
# define E_SHLVL "mSH_LVL"
# define E_PP_R "mSH_PIPEFD_R"
# define E_PP_W "mSH_PIPEFD_W"
# define E_EXIT "mSH_EXIT" 
# define E_SHCMD "mSH_CMD"
# define E_SHPWD "PWD"
# define E_SHLDPATH "mSH_LDPATH"
# define E_SHOPWD "OLDPWD"
# define E_HERE_CC "mSH_HERECC"
# define L_SHPIPE "mSH_PIPE"
# define E_ECHOLEN "mSH_ECHOLEN"

# define P_SHSELF "mSH_SELF"
# define P_SHHIS "mSH_HISTORY"
# define P_SHCFG "mSH_CONFIG"

/// diff listex
# define L_SHCMDIDX "mSH_CMDIDX"
# define L_SHCMDLIST "mSH_CMDLIST"
# define L_SHCMDSIZE "mSH_CMDSIZE"
# define L_HISTORY "mSH_ENCHIS"

# define D_SHCMDIDX "mSHD_CMDIDX"
# define D_SHCMDLIST "mSHD_CMDLIST"
# define D_SHCMDSIZE "mSHD_CMDSIZE"
# define D_HISTORY "ENCHIS"
# define D_SHLES "mSH_LES"

# define L_ORIGREAD "mSH_OREAD"
# define L_ORIGWRITE "mSH_OWRITE"
# define L_MREAD_F "mSH_MREADF"
# define L_MREAD_S "mSH_MREADS"
# define L_MWRITE_F "mSH_MWRITEF"
# define L_MWRITE_S "mSH_MWRITES"

# define COL_INIT 0
# define COL_ADD 1
# define COL_REMOVE 2
# define COL_EXIT 3
# define EXIT_NOW 1
# define EXIT_OTHERS 2
# define EXIT_BOTH 3
# define EXIT_CBOTH 5

# define VK_TAB 9
# define VK_CTRL_D 4
# define VK_ESC 27
# define VK_ESCC 91
# define VK_UP 65
# define VK_DOWN 66
# define VK_RIGHT 67
# define VK_LEFT 68
# define VK_DELETE 51
# define VK_BACKSPACE 127

# define P_READ 0
# define P_WRITE 1

# define FD_SET_IN 5
# define FD_SET_IN_DEL 6
# define FD_SET_OUT 7
# define FD_SET_OUTA 8
# define FD_DA 8
# define FD_DB 5
# define FD_DC 2
# define FD_SDC "\2"
# define FD_DD 3
# define FD_DE 7
# define FD_DF 6
# define FD_DG 4
# define FD_DH 28
# define FD_DI 30
# define FD_DJ 31

# define FD_SDF "\6"
# define FD_SDH "\28"
# define FD_SDK "#"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SOFF 1024
# define SMASKSIZE 8
# define EXIT_SIGNAL SIGTERM
# define MAINR_SIGNAL SIGUSR1
# define MAINW_SIGNAL SIGUSR2
# define ALTR_SIGNAL SIGTTIN
# define ALTW_SIGNAL SIGTTOU

# define PAC_DELAY 8192
# define PAC_WARNING 256
# define PAC_HSIZE 5
# define PAC_DSIZE 9
# define PAC_BSIZE 14
# define PAC_RSIZE 25
# define ARG_STR_SIZE 5
# define EOF_TRANSMISSION 23

#endif
