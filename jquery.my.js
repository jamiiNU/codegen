
/* My other jquery addons */
/* Show or hide element */
(function($){
$.fn.show_hide = function(show){
	//this.toggle(show);
	if(show) this.show();
	else this.hide();
	return;
	if(show)
		this.slideDown();
	else
		this.slideUp();
}})(jQuery);

(function($){
$.fn.use = function(flag){
	this.find('*').css("color", (flag?"":"#b0b0b0"));
	this.find('td:nth-child(5) a').text(flag ? '√' : '×')
		.css('color', (flag ? 'blue' : '#b0b0b0'))
		.css('font', 'bold Verdana,"Lucida Sans Unicode"');
}})(jQuery);

(function($){
$.fn.float_title = function(){
	var msie = true;//$.browser.msie;
	//if(msie && $.browser.version < 7) return;
	
	var table = $('<table border="0"></table>')
		.append(this.clone())
		.addClass(msie ? 'float_table_header_ie' : 'float_table_header');
	var td = table.find('td');
	
	var ref = this;
	function adjust_float_size(){
		table.width(ref.outerWidth());
		ref.find('td').each(function(i){
			var o = $(this);
			$(td[i]).addClass('float_title').width(o.width()).height(o.height());
		});
	}
	
	adjust_float_size();
	$(document.body).append(table.hide());
	
	$(window).resize(function(){
		adjust_float_size();
		//setTimeout(function(){adjust_float_size();}, 1000);
	}).scroll(function(){
		table.toggle(ref.position().top < $(window).scrollTop());
		if(msie){
			table.css('left', ref.position().left, 0)
				.css('top', $(window).scrollTop());
		}
		else
			table.css('left', -$(window).scrollLeft() + ref.position().left);
	});	
}})(jQuery);

/* Set elements config */	
jQuery.set_func = function set_func(cfg, group){
	if(group !== undefined) group = group+'_';
	else group = '';
	return function(name){
		var o = document.getElementById(group+name);
		if(o){
			if(o.type == 'checkbox')
				o.checked = (cfg[name] ? 'checked' : '');
			else
				o.value = cfg[name];
		}
		else{/* for radio only */
			o = document.forms.fm[group+name+'_'];
			$(o).filter('[value="'+cfg[name]+'"]').prop('checked', true)
		}
	}
}

/* Get elements config */
jQuery.get_func = function get_func(cfg, group) {
	if(group !== undefined) group = group+'_';
	else group = '';
	return function get(name){
		var o = document.getElementById(group+name);
		if(o){		
			if(o.type == 'checkbox')
				cfg[name] = (o.checked == '' ? 0 : 1);
			else
				cfg[name] = (typeof(cfg[name]) == 'number' ? o.value - 0 : o.value);
		}
		else{/* for radio only */
			o = document.forms.fm[group+name+'_'];
			if(o){
				var v = $(o).filter(':checked').val();
				cfg[name] = (typeof(cfg[name]) == 'number' ? v - 0 : v);
			}
		}
	}
}

jQuery.get_func_name = function get_func_name(cfg, group, name) {
	var o;

	if (group !== undefined) group = group + '_';
	else group = '';

	o = document.getElementById(group + name);
	if (o) {
		if (o.type == 'checkbox')
			cfg[name] = (o.checked == '' ? 0 : 1);
		else
			cfg[name] = (typeof (cfg[name]) == 'number' ? o.value - 0 : o.value);
	}
	else {/* for radio only */
		o = document.forms.fm[group + name + '_'];
		if (o) {
			var v = $(o).filter(':checked').val();
			cfg[name] = (typeof (cfg[name]) == 'number' ? v - 0 : v);
		}
	}
}

jQuery.rewrite_index = function rewrite_index(min, max, obj) {
	/* Overwrite config */
	if(location.hash){
		var ma = location.hash.match(/#(\d+)/);
		if(ma){
			var index = parseInt(ma[1]);
			if(index >= min && index <= max) obj.Index = index;
		}
	}
}

