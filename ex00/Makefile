.PHONY: all clean fclean re f fclear c clear

#############################################################################################
#																							#
#										// Directories										#
#																							#
#############################################################################################


# Directories
SRC_DIR				:=		./src/
HEADERS_DIR			:=		./inc/

# Sub Directories

# for a new DIR add a new :
# NEW_DIR			:=		new/



#############################################################################################
#																							#
#										// SOURCE											#
#																							#
#############################################################################################


HEADERS_D			:=		./incs/


HEADERS				:=		ScalarConverter.hpp



SRC					:=		main.cpp \
							ScalarConverter.cpp


# for a new SRC add a new :
# SRC_NEW				:=




# Every now src_dir add a addprifix like that :
#	$(addprefix $(NEW_DIR), $(SRC_NEW))


SRCS				=		$(SRC)


#	#################################################################################	#
#	#		#			No need To change anything below this line.			#		#	#
#	#################################################################################	#


#############################################################################################
#																							#
#										// Variable											#
#																							#
#############################################################################################


NAME				=		cpp
CC					=		c++
INCLUDES			=		-I$(HEADERS_DIR)
CPPFLAGS			=		-Wall -Werror -Wextra -std=c++98 $(INCLUDES)
CPPFLAGSS			=		-Weverything						 -Wno-padded -Wno-documentation-unknown-command -Wno-documentation -std=c++98 $(INCLUDES)
NPD					=		--no-print-directory
MAKE				:=		$(MAKE) -j $(NPD)
RM					=		rm -fr


#############################################################################################
#																							#
#										// OBJECT											#
#																							#
#############################################################################################


OBJS_DIR			:=		.objs/
OBJS_FILES			:=		$(SRCS:.cpp=.o)
OBJS				:=		$(addprefix $(OBJS_DIR), $(OBJS_FILES))


DEPS_DIR			:=		deps/
DEPS_FILES			:=		$(OBJS_FILES:.o=.d)
DEPS				:=		$(addprefix $(DEPS_DIR), $(DEPS_FILES))


#############################################################################################
#																							#
#									// Rules Compilation									#
#																							#
#############################################################################################


all					:		$(NAME)


$(NAME)				:		$(OBJS)
		$(CC) $^ $(CPPFLAGS) -o $(NAME)



$(DEPS_DIR) 		:
		mkdir -p $(DEPS_DIR)


$(OBJS_DIR)%.o : $(SRC_DIR)%.cpp Makefile | $(DEPS_DIR)
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEPS_DIR)$*)
	$(CC) $(CPPFLAGS) $(INCLUDES) -MP -MMD -MF $(DEPS_DIR)$*.d -c $< -o $@

#############################################################################################
#																							#
#									// clean fclean re										#
#																							#
#############################################################################################


clean 				:
			$(RM) $(OBJS_DIR)
			$(RM) $(DEPS_DIR)


fclean 				:
			$(RM) $(NAME)
			$(RM) $(OBJS_DIR)
			$(RM) $(DEPS_DIR)


re 					:	 fclean all


#############################################################################################
#																							#
#										// Allias											#
#																							#
#############################################################################################


c					:	clear
clear				:	clean

f					:	fclean
fclear				:	fclean

-include $(DEPS)
