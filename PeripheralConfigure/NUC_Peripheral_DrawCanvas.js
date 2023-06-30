(function () {
	function DrawCanvas(canvasId, chipType, input_setting, module) {
	var canvas = document.getElementById(canvasId);
		if (canvas.getContext) {
			var ctx = canvas.getContext("2d");
				start_pos_x = 330,
				start_pos_y = 50,
				pin_width = 35,
				pin_height = 70,
				canvas_width = canvas.width,
				headerfilepath = "PeripheralConfigure/" + chipType + "/psio.h",
				i = 0,
				pin_enable_count = 0,
				peripheral_setting = [],
				peripheral_clock = 0;

			ctx.clearRect(0, 0, canvas.width,canvas.height);
			peripheral_setting = input_setting.peripheral;
			peripheral_clock = GetPeripheralClock(input_setting.clock, module);

			try {
				InputSettingParsingTagID(input_setting.peripheralAllIds, module);
				if (module === "PSIO") {
					//slot_count: width of slot (0~15)
					//init_slot, end_slot: start and end slot of repeat mode (0: not use, 1~8: slot0~7)
					//loop_count: slot repeat count of repeat mode (0~62, 63: loop until stop)
					// trg_src: 0: SW trigger, 1: falling trigger, 2: rising trigger, 3: fall_rising trigger
					var slot_info = [
						{ SlotEnable: 0, slot_count: [0, 0, 0, 0, 0, 0, 0, 0], init_slot: 0, end_slot: 0, loop_count: 0, trg_src: 0, repeat_mode: 0},
						{ SlotEnable: 0, slot_count: [0, 0, 0, 0, 0, 0, 0, 0], init_slot: 0, end_slot: 0, loop_count: 0, trg_src: 0, repeat_mode: 0},
						{ SlotEnable: 0, slot_count: [0, 0, 0, 0, 0, 0, 0, 0], init_slot: 0, end_slot: 0, loop_count: 0, trg_src: 0, repeat_mode: 0},
						{ SlotEnable: 0, slot_count: [0, 0, 0, 0, 0, 0, 0, 0], init_slot: 0, end_slot: 0, loop_count: 0, trg_src: 0, repeat_mode: 0}
					];

					//initial and interval: 0: Low, 1: High, 2: Last Output, 3: Toggle
					//io_mode: 0:input, 1:output, 2:open-drain, 3:quasi
					//CPSLOT: link checkpoint and slot (0: not use, 1~8: slot0~7)
					//CPACT: checkpoint status (0:output low, 1:output high, 2:output form data buffer, 3: output toggle
					//							4:input data buffer, 5:input status, 6:input staus record and update)
					var pin_info = [
						{ PinEnable: 0, SlotCtlSel: 0, interval: 0, initial: 0,	io_mode: 0, CPSLOT: [0, 0, 0, 0, 0, 0, 0, 0], CPACT: [0, 0, 0, 0, 0, 0, 0, 0] },
						{ PinEnable: 0, SlotCtlSel: 0, interval: 0, initial: 0,	io_mode: 0, CPSLOT: [0, 0, 0, 0, 0, 0, 0, 0], CPACT: [0, 0, 0, 0, 0, 0, 0, 0] },
						{ PinEnable: 0, SlotCtlSel: 0, interval: 0, initial: 0,	io_mode: 0, CPSLOT: [0, 0, 0, 0, 0, 0, 0, 0], CPACT: [0, 0, 0, 0, 0, 0, 0, 0] },
						{ PinEnable: 0, SlotCtlSel: 0, interval: 0, initial: 0,	io_mode: 0, CPSLOT: [0, 0, 0, 0, 0, 0, 0, 0], CPACT: [0, 0, 0, 0, 0, 0, 0, 0] },
						{ PinEnable: 0, SlotCtlSel: 0, interval: 0, initial: 0,	io_mode: 0, CPSLOT: [0, 0, 0, 0, 0, 0, 0, 0], CPACT: [0, 0, 0, 0, 0, 0, 0, 0] },
						{ PinEnable: 0, SlotCtlSel: 0, interval: 0, initial: 0,	io_mode: 0, CPSLOT: [0, 0, 0, 0, 0, 0, 0, 0], CPACT: [0, 0, 0, 0, 0, 0, 0, 0] },
						{ PinEnable: 0, SlotCtlSel: 0, interval: 0, initial: 0, io_mode: 0, CPSLOT: [0, 0, 0, 0, 0, 0, 0, 0], CPACT: [0, 0, 0, 0, 0, 0, 0, 0] },
						{ PinEnable: 0, SlotCtlSel: 0, interval: 0, initial: 0,	io_mode: 0, CPSLOT: [0, 0, 0, 0, 0, 0, 0, 0], CPACT: [0, 0, 0, 0, 0, 0, 0, 0] }
					];

					//Transform string to value by psio.h define
					InputSettingStrToValue(peripheral_setting, headerfilepath)
					//Fill PSIO setting into slot_info and pin_info
					InputSettingParsingPSIO(peripheral_setting, slot_info, pin_info);
					for (i = 0; i < pin_info.length; i += 1) {
						if (pin_info[i].PinEnable) {
							pin_enable_count = pin_enable_count + 1;
						}
					}
					canvas.setAttribute("height", start_pos_y + 250 + pin_enable_count * 80);
					ToolTip_Setting(ctx, start_pos_x, start_pos_y, pin_width, pin_height / 2, peripheral_clock);
					//draw background color for slot waveform
					Slot_Background_Setting(ctx, start_pos_x, start_pos_y + 10, canvas_width * 2, pin_height / 2, 4, "rgba(0, 200, 0, 0.1)");
					//draw background color for pin waveform
					Pin_Background_Setting(ctx, start_pos_x, start_pos_y + 250, canvas_width * 2, pin_height, 8, "rgba(0, 0, 200, 0.1)", pin_info);
					Clock_Waveform(ctx, start_pos_x, start_pos_y, pin_width, pin_height / 2, (canvas_width - start_pos_x) / pin_width, pin_enable_count);
					Slot_Waveform(ctx, start_pos_x, start_pos_y + 10, pin_width, pin_height / 2, slot_info, pin_info);
					Pin_Initial_Status(ctx, start_pos_x - 100, start_pos_y + 250, pin_width, pin_height, slot_info, pin_info);
					Pin_Waveform(ctx, start_pos_x, start_pos_y + 250, pin_width * 2, pin_height, slot_info, pin_info, canvas_width);
					return true;
				}
				else if (module === "WDT") {
					var rect_width,
						rect_height = 30,
						wdt_setting = {	Timeout: 0,
										ResetDelay: 0,
										ResetEnable: 0,
										InterruptEnable: 0,
										WakeupEnable: 0};

					if (InputSettingParsing(peripheral_setting, wdt_setting, module) === false)
						return false;

					start_pos_x = 10;
					start_pos_y = 30;
					canvas.setAttribute("height", start_pos_y + rect_height + 10);
					if (peripheral_clock === 0) {
						DisplayMessage(ctx, module + " clock not enable!", 15, 20, 0);
					}
					else {
						//Reset Counter
						rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "Reset Counter", true);
						start_pos_x = start_pos_x + rect_width + 10;
						//Arrow
						DrawArrow(ctx, start_pos_x + 10, start_pos_y + 15);
						start_pos_x = start_pos_x + 30;
						//WatchDog Time Out Interval
						i = wdt_setting.Timeout / peripheral_clock.toFloat();
						i = parseFloat(i.toFixed(6));
						rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, i + " seconds", true);

						start_pos_x = start_pos_x + rect_width + 10;
						//Arrow
						DrawArrow(ctx, start_pos_x + 10, start_pos_y + 15);
						start_pos_x = start_pos_x + 30;
						//WatchDog Interrupt Enable
						rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "WatchDog Interrupt", wdt_setting.InterruptEnable);
						start_pos_x = start_pos_x + rect_width + 10;
						//WatchDog Wakeup Enable
						rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "Wakeup CPU", wdt_setting.WakeupEnable);
						start_pos_x = start_pos_x + rect_width + 10;
						//Arrow
						DrawArrow(ctx, start_pos_x + 10, start_pos_y + 15);
						start_pos_x = start_pos_x + 30;
						//WatchDog Reset Delay
						i = wdt_setting.ResetDelay / peripheral_clock.toFloat();
						i = parseFloat(i.toFixed(6));
						rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, i + " seconds", true);

						start_pos_x = start_pos_x + rect_width + 10;
						DrawArrow(ctx, start_pos_x + 10, start_pos_y + 15);
						start_pos_x = start_pos_x + 30;
						//WatchDog Reset Enable
						rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "WatchDog Reset CPU", wdt_setting.ResetEnable);
					}
					return true;
				}
				else if (module.indexOf("TIMER") !== -1) {
					var clock_time_string,
						timer_counter_value = 0,
						real_frequency = 0,
						rect_width,
						rect_height = 30,
						timer_setting = { FuncSel: 0,
										  TimerFreq: 0,
										  TimerCmp: 0,
										  TimerPrescale: 0,
										  TimerMode: 0,
										  InterruptEnable: 0,
										  TimerChannel: 0};

					if (InputSettingParsing(peripheral_setting, timer_setting, module) === false) {
						return false;
					}

					if (timer_setting.FuncSel !== 1)
						return false;

					start_pos_x = 10;
					start_pos_y = 10;

					canvas.setAttribute("height", rect_height + 110);

					//ticks time
					if (peripheral_clock === 0) {
						DisplayMessage(ctx, module + " clock not enable!", start_pos_x, start_pos_y + 50, 0);
					}
					else {
						if ((timer_setting.TimerFreq > 0) && (timer_setting.TimerCmp == 0)) {
							real_frequency = GetTIMERFrequency(peripheral_clock.toFloat(), timer_setting);
						}
						else {
							real_frequency = peripheral_clock.toFloat() / (timer_setting.TimerPrescale + 1) / timer_setting.TimerCmp;
						}
						if (real_frequency < 1) {
							DisplayMessage(ctx, "TIMER incorrect setting!", start_pos_x, start_pos_y + 50, 0);
							return true;
						}
						//ticks time
						i = timer_setting.TimerCmp / real_frequency;
						//i = parseFloat(i.toFixed(8));
						//remove the end of the string '0'
						//while ( i.substring(i.length-1) == '0' ) {
						//	i = i.substring(0, i.length-1);
						//}
						clock_time_string = timer_setting.TimerCmp + " ticks = " + ToSecond(i);
						DisplayMessage(ctx, clock_time_string, start_pos_x, start_pos_y + 50, 1);
						DisplayMessage(ctx, "Timer working frequency = " + real_frequency.toHzString(), start_pos_x, start_pos_y + 80, 1);
						DisplayMessage(ctx, "Clock source frequency = " + peripheral_clock, start_pos_x, start_pos_y + 110, 1);

						//Counter -> TCMPR
						rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "Counter 0 -> " + timer_setting.TimerCmp, true);
						start_pos_x = start_pos_x + rect_width + 10;
						//Arrow
						DrawArrow(ctx, start_pos_x + 10, start_pos_y + 15);
						start_pos_x = start_pos_x + 30;
						//Interrupt
						rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "Interrupt", timer_setting.InterruptEnable);
						if (timer_setting.TimerMode !== 0) {
							start_pos_x = start_pos_x + rect_width + 10;
							//Arrow
							DrawArrow(ctx, start_pos_x + 10, start_pos_y + 15);
							start_pos_x = start_pos_x + 30;
							//Reset Counter
							if (timer_setting.TimerMode === 3) {
								timer_counter_value = timer_setting.TimerCmp + 1;
								rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "Counter " + timer_counter_value + " -> TIMER Max value (overflow)", true);
							}
							else {
								rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "Reset Counter", true);
							}
							if ((timer_setting.TimerMode === 1) || (timer_setting.TimerMode === 2)){
								start_pos_x = start_pos_x + rect_width + 10;
								//Arrow
								DrawArrow(ctx, start_pos_x + 10, start_pos_y + 15);
								start_pos_x = start_pos_x + 30;
								//Restart Counter
								if (timer_setting.TimerMode === 2) {
									rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "Toggle Output T" + timer_setting.TimerChannel, true);
								}
								else {
									rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "Restart Counter 0 -> " + timer_setting.TimerCmp, true);
									start_pos_x = start_pos_x + rect_width + 10;
									//...
									rect_width = DrawRect(ctx, start_pos_x, start_pos_y, rect_width, rect_height, "...", true);
								}
							}
						}
					}

					return true;
				}
				else if (module.indexOf("UART") !== -1) {
					var rect_width,
						rect_height = 30,
						real_baudrate = 0,
						uart_setting = { UartBaudrate: 0 };

					if (InputSettingParsing(peripheral_setting, uart_setting, module) === false) {
						return false;
					}

					start_pos_x = 10;
					start_pos_y = 10;

					canvas.setAttribute("height", rect_height + 30);
					if (peripheral_clock === 0) {
						DisplayMessage(ctx, module + " clock not enable!", start_pos_x, start_pos_y + 10, 0);
					}
					else {
						real_baudrate = GetUartBaudRate(peripheral_clock.toFloat(), uart_setting.UartBaudrate);
						if (real_baudrate > 0) {
							DisplayMessage(ctx, "Uart working baud rate = " + real_baudrate + " bps", start_pos_x, start_pos_y + 10, 1);
						}
						else {
							DisplayMessage(ctx, "Uart baud rate incorrect setting!", start_pos_x, start_pos_y + 10, 1);
						}
						DisplayMessage(ctx, "Clock source frequency = " + peripheral_clock, start_pos_x, start_pos_y + 30, 1);
					}
					return true;
				}
				else if (module.indexOf("BPWM") !== -1) {
					return false;
				}
				else if (module.indexOf("PWM") !== -1) {
					var rect_width,
						rect_height = 30,
						real_frequency = 0,
						period_time = 0,
						pwm_setting = { PwmSrcSelect: 0,
										PwmFreq: 0,
										PwmCountType: 0,
										PwmPrescale: 0,
										PwmPeriod: 0};

					if (InputSettingParsing(peripheral_setting, pwm_setting, module) === false) {
						return false;
					}

					//Select PWM source clock
					if (pwm_setting.PwmSrcSelect !== 0) {
						return false;
					}

					start_pos_x = 10;
					start_pos_y = 10;

					canvas.setAttribute("height", rect_height + 50);
					if (peripheral_clock === 0) {
						DisplayMessage(ctx, module + " clock not enable!", start_pos_x, start_pos_y + 10, 0);
					}
					else {
						DisplayMessage(ctx, "Clock source frequency = " + peripheral_clock, start_pos_x, start_pos_y + 10, 1);
						if ((pwm_setting.PwmFreq == 0) && ((pwm_setting.PwmPeriod == 0) || (pwm_setting.PwmPrescale == 0))) {
							return false;
						}
						else if (pwm_setting.PwmFreq > peripheral_clock.toFloat()) {
							ctx.fillText("Incorrect setting! PWM frequency is greater then clock source frequency.", start_pos_x, start_pos_y + 30);
						}
						else if (pwm_setting.PwmFreq > 0) {
							real_frequency = GetPWMFrequency(peripheral_clock.toFloat(), pwm_setting.PwmFreq);
							ctx.fillText("PWM working frequency = " + real_frequency.toHzString(), start_pos_x, start_pos_y + 30);
						}
						else {
							if (pwm_setting.PwmCountType == 2) {
								real_frequency = peripheral_clock.toFloat() / ((2 * pwm_setting.PwmPeriod) * (pwm_setting.PwmPrescale + 1));
								period_time = 2 * pwm_setting.PwmPeriod * (pwm_setting.PwmPrescale + 1) / peripheral_clock.toFloat();
							}
							else {
								real_frequency = peripheral_clock.toFloat() / ((pwm_setting.PwmPeriod + 1) * (pwm_setting.PwmPrescale + 1));
								period_time = (pwm_setting.PwmPeriod +1) * (pwm_setting.PwmPrescale + 1) / peripheral_clock.toFloat();
							}
							if ((real_frequency == 0) || (period_time == 0)) {
								ctx.fillText("PWM incorrect setting! PWM frequency or PWM period value is 0.", start_pos_x, start_pos_y + 30);
								return true;
							}
							real_frequency = Math.floor(real_frequency);
							ctx.fillText("PWM working frequency = " + real_frequency.toHzString(), start_pos_x, start_pos_y + 30);
							ctx.fillText("PWM period time = " + ToSecond(period_time), start_pos_x, start_pos_y + 50);
						}
					}
					return true;
				}
				else {
					return false;
				}
			}
			catch (err) {
				canvas.setAttribute("height", 40);
				DisplayMessage(ctx, err, 15, 20, 0);
				return true;
			}
		}
	}

	//print message on canvas, mode 0: not enable module clock
	function DisplayMessage(ctx, msg, pos_x, pos_y, mode) {
		if (mode == 0) {
			ctx.fillStyle = "black";
			ctx.textAlign = "left";
			ctx.font="20px Arial";
			ctx.fillText (msg, pos_x, pos_y);
		}
		else {
			ctx.fillStyle = "blue";
			ctx.textAlign = "left";
			ctx.font="14px Arial";
			ctx.fillText(msg, pos_x, pos_y);
		}
	}
	// convert seconds -> mini, micro, nano seconds
	function ToSecond(value) {
		var returnSecString = 's';

		if (value < 0.1) {
			value = value * 1000;
			returnSecString = 'ms';
		}
		if (value < 0.1) {
			value = value * 1000;
			returnSecString = 'us';
		}
		if (value < 0.1) {
			value = value * 1000;
			returnSecString = 'ns';
		}
		returnSecString = value.toFixed(4) + returnSecString;
		return returnSecString;
	}

	function getPropertyNames(obj) {
		var moduleNames = [],
			index = 0,
			name;

		for (name in obj) {
			if (obj.hasOwnProperty(name)) {
				moduleNames[index] = name;
				index += 1;
			}
		}
		index = null;

		return moduleNames;
	}
	function InputSettingStrToValue(psio_setting, filepath) {
		var i,
			j,
			newReadSnippetFile,
			tempString,
			tempString1,
			psio_key = [],
			psio_value = [];

		// read psio.h file
		try {
			newReadSnippetFile = $.ajax({ url: filepath, async: false }).responseText.replace(/\r/g, "");
		}
		catch (err) { throw "Cannot draw diagram. PSIO header file not found!"; }

		//parsing psio.h define and value
		while (newReadSnippetFile.indexOf('\n') !== -1) {
			tempString = newReadSnippetFile.slicePriorToX('\n').trim();
			if ((tempString.indexOf('#define') !== -1) && (tempString.indexOf('UL') !== -1)) {
				tempString = tempString.sliceBetweenXandX('#define', 'UL').replace('(','');
				tempString1 = tempString.slicePriorToX('0x').trim();
				psio_key.push(tempString1);
				tempString1 = '0x' + tempString.sliceAfterX('0x').trim();
				if (isNaN(parseInt(tempString1))) {
					throw "Cannot parsing define macro of PSIO header file!";
				}
				else {
					psio_value.push(parseInt(tempString1));
				}
			}
			newReadSnippetFile = newReadSnippetFile.sliceAfterX('\n');
		}

		PSIOProperties = getPropertyNames(psio_setting);

		for (i = 0; i < PSIOProperties.length; i += 1) {
			for (j = 0; j < psio_key.length; j += 1) {
				if (isNaN(psio_setting[PSIOProperties[i]])) {
					if (psio_setting[PSIOProperties[i]] === psio_key[j]) {
						psio_setting[PSIOProperties[i]] = psio_value[j];
					}
				}
			}
		}
	}
	//Get clock source frequency from clock config tool setting
	function GetPeripheralClock(clock_setting, module) {
		var i,
			clock_id_string,
			Properties = [];

		module = module.toLowerCase();
		if (module.indexOf('timer') !== -1) {
			module = module.replace('timer', 'tmr');
		}
		else if (module.indexOf('pwm') !== -1) {
			module = module.slicePriorToX('_').trim();
		}
		Properties = getPropertyNames(clock_setting);
		for (i = 0; i < Properties.length; i += 1) {
			clock_id_string = Properties[i].toLowerCase();
			if (clock_id_string === module) {
				return clock_setting[Properties[i]];
			}
		}

		return 0;
	}
	function GetTIMERFrequency(peripheral_clock, timer_setting) {
		var cmpr = 0,
			prescale = 0,
			real_frequency = 0,
            peripheral_clock1 = 0,
			timer_freq = timer_setting.TimerFreq;

        peripheral_clock1 = peripheral_clock;
		// Fastest possible timer working freq is (peripheral_clock / 2)
		if (timer_freq > (peripheral_clock / 2)) {
			cmpr = 2;
		}
		else {
			if (peripheral_clock > 64000000) {
				prescale = 7;    // real prescaler value is 8
				peripheral_clock = peripheral_clock >> 3;
			}
			else if (peripheral_clock > 32000000) {
				prescale = 3;    // real prescaler value is 4
				peripheral_clock = peripheral_clock >> 2;
			}
			else if (peripheral_clock > 16000000) {
				prescale = 1;    // real prescaler value is 2
				peripheral_clock = peripheral_clock >> 1;
			}

			cmpr = Math.floor(peripheral_clock / timer_freq);
		}
		if (cmpr > 0) {
			real_frequency = peripheral_clock1 / (cmpr * (prescale + 1));
			timer_setting.TimerCmp = cmpr;
		}
		else {
			real_frequency = 0;
			timer_setting.TimerCmp = 0;
		}

		return Math.floor(real_frequency);
	}
	function GetUartBaudRate(peripheral_clock, uart_baudrate) {
		var mode_div = 0,
			baudrate = 0;

		//Mode2 divider
		mode_div = (peripheral_clock / uart_baudrate) - 2;
		mode_div = Math.round(mode_div);
		if (mode_div < 0) {
			return 0;
		}
        if (mode_div > 0xFFFF) {
			//Mode0 divider
            mode_div = (peripheral_clock / uart_baudrate / 16) - 2;
			mode_div = Math.round(mode_div);
			if (mode_div < 0) {
				return 0;
			}
			baudrate = peripheral_clock / (16 * (mode_div + 2));
        }
        else {
			baudrate = peripheral_clock / (mode_div + 2);
        }
		return Math.round(baudrate);
	}
	function GetPWMFrequency(peripheral_clock, pwm_freq) {
		var cnr = 0,	//PERIOD
			prescale = 1,
			real_frequency = 0;

		if (pwm_freq > 0) {
			for (prescale = 1; prescale < 0xFFF; prescale+=1) {
				cnr = (peripheral_clock / pwm_freq) / prescale;
				cnr = Math.floor(cnr);
				if (cnr <= 0x10000) {
					break;
				}
			}
			if (cnr > 0) {
				real_frequency = peripheral_clock / (prescale * cnr);
				return Math.floor(real_frequency);
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	function InputSettingParsingTagID(tag_ids, module_name) {
		var i = 0,
			re,
			wdt_ids = ["wdt_timeoutselect", "wdt_resetdelayselect", "wdt_resetenableradio", "wdt_intenablecheckbox", "wdt_wakeupenablecheckbox"],
			timer_ids = ["timer[0-3]moderadio", "timer[0-3]intcheckbox", "timer[0-3]cmphextext"],
			psio_ids = ["slotctl[0-3]en", "slotctl[0-3]initslot", "slotctl[0-3]endslot", "slotctl[0-3]loopcount", "slotctl[0-3]triggertype", "slotctl[0-3]repeatmode", "slotctl[0-3]slot[0-15]count", "pin[0-7]en", "pin[0-7]slotcontrollerselect[0-3]", "pin[0-7]iomode", "pin[0-7]initstate", "pin[0-7]intervalstate", "pin[0-7]cp[0-7]slt", "pin[0-7]cp[0-7]act"],
			uart_ids = ["baudrateinteger"],
			pwm_ids = ["freqinteger", "prescalerinteger", "periodinteger", "clksrcselect", "cnttypeselect"];

		tag_ids = tag_ids.toLowerCase();
		if (module_name === "WDT") {
			for (i = 0; i < wdt_ids.length; i +=1) {
				if (tag_ids.indexOf(":" + wdt_ids[i] + "/") === -1) {
					throw "Cannot draw diagram. '" + wdt_ids[i] + "' tag id not found!";
				}
			}
		}
		else if (module_name.indexOf("TIMER") !== -1) {
			for (i = 0; i < timer_ids.length; i +=1) {
				re = ":" + timer_ids[i] + "/";
				if (tag_ids.search(re) === -1) {
					throw "Cannot draw diagram. '" + timer_ids[i] + "' tag id not found!";
				}
			}
		}
		else if (module_name.indexOf("PSIO") !== -1) {
			for (i = 0; i < psio_ids.length; i +=1) {
				re = ":" + psio_ids[i] + "/";
				if (tag_ids.search(re) === -1) {
					throw "Cannot draw diagram. '" + psio_ids[i] + "' tag id not found!";
				}
			}
		}
		else if (module_name.indexOf("UART") !== -1) {
			for (i = 0; i < uart_ids.length; i +=1) {
				re = uart_ids[i] + "/";
				if (tag_ids.search(re) === -1) {
					throw "Cannot draw diagram. '" + uart_ids[i] + "' tag id not found!";
				}
			}
		}
		else if (module_name.indexOf("BPWM") !== -1) {
		}
		else if (module_name.indexOf("PWM") !== -1) {
			for (i = 0; i < uart_ids.length; i +=1) {
				re = pwm_ids[i] + "/";
				if (tag_ids.search(re) === -1) {
					throw "Cannot draw diagram. '" + uart_ids[i] + "' tag id not found!";
				}
			}
		}
	}
	function InputSettingParsingPSIO(psio_setting, slot_info, pin_info) {
		var i,
			slotctl_index,
			cp_index,
			slot_index,
			pin_index,
			psio_id_string,
			PSIOProperties = [];
			bFounded = false;

		PSIOProperties = getPropertyNames(psio_setting);

		for (i = 0; i < PSIOProperties.length; i += 1) {
			psio_id_string = PSIOProperties[i].toLowerCase();

			for (slotctl_index = 0; slotctl_index < slot_info.length; slotctl_index += 1) {
				if (psio_id_string.indexOf("slotctl" + slotctl_index) !== -1) {
					if (psio_id_string.indexOf("init") !== -1) {
						slot_info[slotctl_index].init_slot = psio_setting[PSIOProperties[i]];
						bFounded = true;
					}
					else if (psio_id_string.indexOf("end") !== -1) {
						slot_info[slotctl_index].end_slot = psio_setting[PSIOProperties[i]];
						bFounded = true;
					}
					else if (psio_id_string.indexOf("loop") !== -1) {
						slot_info[slotctl_index].loop_count = psio_setting[PSIOProperties[i]];
						bFounded = true;
					}
					else if (psio_id_string.indexOf("trig") !== -1) {
						slot_info[slotctl_index].trg_src = psio_setting[PSIOProperties[i]];
						bFounded = true;
					}
					else if (psio_id_string.indexOf("repeat") !== -1) {
						slot_info[slotctl_index].repeat_mode = psio_setting[PSIOProperties[i]];
						bFounded = true;
					}
					else if (psio_id_string.indexOf("slotctl" + slotctl_index + "en") !== -1) {
						slot_info[slotctl_index].SlotEnable = psio_setting[PSIOProperties[i]];
						bFounded = true;
					}
					else {
						for (slot_index = 0; slot_index < slot_info[slotctl_index].slot_count.length; slot_index += 1) {
							if (psio_id_string.indexOf("slot" + slot_index + "count") !== -1) {
								slot_info[slotctl_index].slot_count[slot_index] = psio_setting[PSIOProperties[i]];
								bFounded = true;
								break;
							}
						}
					}
				}
				if (bFounded) {
					break;
				}
			}

			if (!bFounded) {
				for (pin_index = 0; pin_index < pin_info.length; pin_index += 1) {
					if (psio_id_string.indexOf("pin" + pin_index) !== -1) {
						if ((psio_id_string.indexOf("slot") !== -1) && (psio_id_string.indexOf("select") !== -1)){
							pin_info[pin_index].SlotCtlSel = psio_setting[PSIOProperties[i]];
						}
						else if (psio_id_string.indexOf("iomode") !== -1) {
							pin_info[pin_index].io_mode = psio_setting[PSIOProperties[i]];
						}
						else if (psio_id_string.indexOf("init") !== -1) {
							pin_info[pin_index].initial = psio_setting[PSIOProperties[i]];
						}
						else if (psio_id_string.indexOf("interval") !== -1) {
							pin_info[pin_index].interval = psio_setting[PSIOProperties[i]];
						}
						else if (psio_id_string.indexOf("pin" + pin_index + "en") !== -1) {
							pin_info[pin_index].PinEnable = psio_setting[PSIOProperties[i]];
						}
						else {
							for (cp_index = 0; cp_index < pin_info[pin_index].CPSLOT.length; cp_index += 1) {
								if (psio_id_string.indexOf("cp" + cp_index + "slt") !== -1) {
									pin_info[pin_index].CPSLOT[cp_index] = psio_setting[PSIOProperties[i]];
									break;
								}
								else if (psio_id_string.indexOf("cp" + cp_index + "act") !== -1) {
									pin_info[pin_index].CPACT[cp_index] = psio_setting[PSIOProperties[i]];
									break;
								}
							}
						}
					}
				}
			}
			bFounded = false;
		}
	}
	//Parsing user setting value from tag id
	function InputSettingParsing(input_obj, output_obj, module_name) {
		var i,
			tempString,
			Properties = [],
			name;

		Properties = getPropertyNames(input_obj);

		if (module_name === "WDT") {
			for (i = 0; i < Properties.length; i += 1) {
				id_string = Properties[i].toLowerCase();
				if (id_string.indexOf("timeout") !== -1) {
					tempString = input_obj[Properties[i]];
					if (tempString.indexOf('POW') !== -1) {
						tempString = tempString.sliceAfterX('POW').trim();
						if (isNaN(parseInt(tempString))) {
							throw "Cannot parsing WDT time-out value!";
						}
						else {
							output_obj.Timeout = Math.pow(2, parseInt(tempString));
						}
					}
					else {
						throw "Cannot parsing WDT time-out value!";
					}
				}
				else if (id_string.indexOf("delay") !== -1) {
					tempString = input_obj[Properties[i]];
					if (tempString.indexOf('CLK') !== -1) {
						while(tempString.indexOf('_') !== -1) {
							tempString = tempString.sliceAfterX('_').trim();
						}

						if (isNaN(parseInt(tempString))) {
							throw "Cannot parsing WDT delay value!";
						}
						else {
							output_obj.ResetDelay = parseInt(tempString);
						}
					}
					else {
						throw "Cannot parsing WDT delay value!";
					}
				}
				else if ((id_string.indexOf("reset") !== -1) && (id_string.indexOf("enable") !== -1)){
					if (isNaN(parseInt(input_obj[Properties[i]]))) {
						throw "Cannot parsing WDT reset value!";
					}
					else {
						output_obj.ResetEnable = parseInt(input_obj[Properties[i]]);
					}
				}
				else if ((id_string.indexOf("int") !== -1) && (id_string.indexOf("enable") !== -1)){
					if (isNaN(parseInt(input_obj[Properties[i]]))) {
						throw "Cannot parsing WDT interrupt value!";
					}
					else {
						output_obj.InterruptEnable = parseInt(input_obj[Properties[i]]);
					}
				}
				else if ((id_string.indexOf("wakeup") !== -1) && (id_string.indexOf("enable") !== -1)){
					if (isNaN(parseInt(input_obj[Properties[i]]))) {
						throw "Cannot parsing WDT wake-up enable value!";
					}
					else {
						output_obj.WakeupEnable = parseInt(input_obj[Properties[i]]);
					}
				}
			}
		}
		else if (module_name.indexOf("TIMER") !== -1) {
			for (i = 0; i < Properties.length; i += 1) {
				id_string = Properties[i].toLowerCase();
				if (id_string.indexOf("capture") === -1) {
					if (id_string.indexOf("funcradio") !== -1) {
						tempString = input_obj[Properties[i]];
						if (tempString.indexOf('FUNC_TIMER') !== -1) {
							output_obj.FuncSel = 1;
							if (id_string.indexOf("timer0") !== -1) {
								output_obj.TimerChannel = 0;
							}
							else if (id_string.indexOf("timer1") !== -1) {
								output_obj.TimerChannel = 1;
							}
							else if (id_string.indexOf("timer2") !== -1) {
								output_obj.TimerChannel = 2;
							}
							else if (id_string.indexOf("timer3") !== -1) {
								output_obj.TimerChannel = 3;
							}
						}
						else {
							return false;
						}
					}
					else {
						output_obj.FuncSel = 1;
						if (id_string.indexOf("timer0") !== -1) {
							output_obj.TimerChannel = 0;
						}
						else if (id_string.indexOf("timer1") !== -1) {
							output_obj.TimerChannel = 1;
						}
						else if (id_string.indexOf("timer2") !== -1) {
							output_obj.TimerChannel = 2;
						}
						else if (id_string.indexOf("timer3") !== -1) {
							output_obj.TimerChannel = 3;
						}
					}

					if (id_string.indexOf("moderadio") !== -1) {
						tempString = input_obj[Properties[i]];
						if (tempString.indexOf('ONESHOT') !== -1) {
							output_obj.TimerMode = 0;
						}
						else if (tempString.indexOf('PERIODIC') !== -1) {
							output_obj.TimerMode = 1;
						}
						else if (tempString.indexOf('TOGGLE') !== -1) {
							output_obj.TimerMode = 2;
						}
						else if (tempString.indexOf('CONTINUOUS') !== -1) {
							output_obj.TimerMode = 3;
						}
						else {
							throw "Cannot parsing TIMER mode value!";
						}
					}
					else if (id_string.indexOf("cmphextext") !== -1) {
						if (isNaN(parseInt(input_obj[Properties[i]]))) {
							throw "Cannot parsing TIMER compare value!";
						}
						else {
							output_obj.TimerCmp = parseInt(input_obj[Properties[i]]);
						}
					}
					else if (id_string.indexOf("intcheckbox") !== -1) {
						if (isNaN(parseInt(input_obj[Properties[i]]))) {
							throw "Cannot parsing TIMER interrupt value!";
						}
						else {
							output_obj.InterruptEnable = parseInt(input_obj[Properties[i]]);
						}
					}
					else if ((id_string.indexOf("freqinteger") !== -1) && (id_string.indexOf("pwm") === -1)) {
						if (isNaN(parseInt(input_obj[Properties[i]]))) {
							throw "Cannot parsing TIMER frequency value!";
						}
						else {
							output_obj.TimerFreq = parseInt(input_obj[Properties[i]]);
						}
					}
					else if ((id_string.indexOf("prescaleinteger") !== -1) && (id_string.indexOf("timer") !== -1)) {
						if (isNaN(parseInt(input_obj[Properties[i]]))) {
							throw "Cannot parsing TIMER prescale value!";
						}
						else {
							output_obj.TimerPrescale = parseInt(input_obj[Properties[i]]);
						}
					}
				}
			}
		}
		else if (module_name.indexOf("UART") !== -1) {
			for (i = 0; i < Properties.length; i += 1) {
				id_string = Properties[i].toLowerCase();
				if (id_string.indexOf("baudrateinteger") !== -1) {
					if (isNaN(parseInt(input_obj[Properties[i]]))) {
						throw "Cannot parsing UART baud rate value!";
					}
					else {
						output_obj.UartBaudrate = parseInt(input_obj[Properties[i]]);
						return true;
					}
				}
			}
		}
		else if (module_name.indexOf("BPWM") !== -1) {
			return false;
		}
		else if (module_name.indexOf("PWM") !== -1) {
			for (i = 0; i < Properties.length; i += 1) {
				id_string = Properties[i].toLowerCase();
				if (id_string.indexOf("freqinteger") !== -1) {
					if (isNaN(parseInt(input_obj[Properties[i]]))) {
						throw "Cannot parsing PWM frequency value!";
					}
					else {
						output_obj.PwmFreq = parseInt(input_obj[Properties[i]]);
					}
				}
				else if (id_string.indexOf("prescalerinteger") !== -1) {
					if (isNaN(parseInt(input_obj[Properties[i]]))) {
						throw "Cannot parsing PWM prescaler value!";
					}
					else {
						output_obj.PwmPrescale = parseInt(input_obj[Properties[i]]);
					}
				}
				else if (id_string.indexOf("periodinteger") !== -1) {
					if (isNaN(parseInt(input_obj[Properties[i]]))) {
						throw "Cannot parsing PWM period value!";
					}
					else {
						output_obj.PwmPeriod = parseInt(input_obj[Properties[i]]);
					}
				}
				else if ((id_string.indexOf("clksrcselect") !== -1) && (id_string.indexOf("dead") === -1)) {
					tempString = input_obj[Properties[i]];
					if (tempString.indexOf("TIMER0") !== -1) {
						output_obj.PwmSrcSelect = 1;
					}
					else if (tempString.indexOf("TIMER1") !== -1) {
						output_obj.PwmSrcSelect = 2;
					}
					else if (tempString.indexOf("TIMER2") !== -1) {
						output_obj.PwmSrcSelect = 3;
					}
					else if (tempString.indexOf("TIMER3") !== -1) {
						output_obj.PwmSrcSelect = 4;
					}
					else if (tempString.indexOf("PWM_CLK") !== -1) {
						output_obj.PwmSrcSelect = 0;
					}
					else {
						return false;
					}
				}
				else if (id_string.indexOf("cnttypeselect") !== -1) {
					tempString = input_obj[Properties[i]];
					if (tempString.indexOf("UP_DOWN") !== -1) {
						output_obj.PwmCountType = 2;
					}
					else if (tempString.indexOf("DOWN") !== -1) {
						output_obj.PwmCountType = 1;
					}
					else if (tempString.indexOf("UP") !== -1) {
						output_obj.PwmCountType = 0;
					}
					else {
						return false;
					}
				}
			}
		}
		else {
			return false;
		}

		return true;
	}
	function ToolTip_Setting(ctx, x, y, width, height, clock) {
		var y_pos = y - height / 2 - 8,
			i;

		ctx.beginPath();
		ctx.font="14px Arial";
		ctx.textAlign = "left";
		ctx.textBaseline = "middle";
		for (i = 0; i < 9; i += 1) {
			ctx.fillStyle = "black";
			switch(i)
			{
			case 0:
				ctx.fillStyle = "black";
				if (clock !== 0) {
					ctx.fillText ("PSIO clock : " + clock, 15, y_pos);
				}
				else {
					ctx.font="20px Arial";
					ctx.fillText ("PSIO clock not enable!", 15, y_pos);
					ctx.font="14px Arial";
				}
				break;
			case 1:
				ctx.fillStyle = "rgba(100, 149, 237, 1)";
				ctx.fillRect (13, y_pos - height / 4, 64, height / 2);
				ctx.fillStyle = "black";
				ctx.fillText ("INSTSUP : Input status record and update", 15, y_pos);
				break;
			case 2:
				ctx.fillStyle = "rgba(100, 149, 237, 1)";
				ctx.fillRect (13, y_pos - height / 4, 46, height / 2);
				ctx.fillStyle = "black";
				ctx.fillText ("INSTS : Input status", 15, y_pos);
				break;
			case 3:
				ctx.fillStyle = "rgba(100, 149, 237, 1)";
				ctx.fillRect (13, y_pos - height / 4, 19, height / 2);
				ctx.fillStyle = "black";
				ctx.fillText ("DI : Input data buffer", 15, y_pos);
				break;
			case 4:
				ctx.fillStyle = "rgba(205, 85, 85, 1)";
				ctx.fillRect (13, y_pos - height / 4, 26, height / 2);
				ctx.fillStyle = "black";
				ctx.fillText ("DO : Output from data buffer", 15, y_pos);
				break;
			case 5:
				ctx.fillStyle = "rgba(205, 85, 85, 1)";
				ctx.fillRect (13, y_pos - height / 4, 24, height / 2);
				ctx.fillStyle = "black";
				ctx.fillText ("TO : Output toggle", 15, y_pos);
				break;
			case 6:
				ctx.fillStyle = "rgba(50, 205, 50, 1)";
				ctx.fillRect (13, y_pos - height / 4, 24, height / 2);
				ctx.fillStyle = "black";
				ctx.fillText ("      : Checkpoint", 15, y_pos);
				break;
			case 7:
				ctx.fillText ("H: High level        T: Toggle", 15, y_pos);
				break;
			case 8:
				ctx.fillText ("L: Low level         O: Last output", 15, y_pos);
				break;
			}
			y_pos = y_pos + height / 2 + 8;
		}
	}
	function Slot_Background_Setting(ctx, x, y, width, height, count, color) {
		var y_pos = y,
			i;

		for (i = 0; i < count; i += 1) {
			ctx.fillStyle = color;
			ctx.fillRect (x, y_pos, width, height);
			y_pos = y_pos + height + 10;
		}
	}
	function Pin_Background_Setting(ctx, x, y, width, height, count, color, pin_info) {
		var y_pos = y,
			i;

		for (i = 0; i < count; i += 1) {
			if (pin_info[i].PinEnable) {
				ctx.fillStyle = color;
				ctx.fillRect (x, y_pos, width, height);
				y_pos = y_pos + height + 10;
			}
		}
	}
	function Clock_Waveform(ctx, x, y, width, height, count, pin_enable_count) {
		var i;

		ctx.fillStyle = "black";
		ctx.beginPath();
		ctx.moveTo(x, y);
		for (i = 1; i <= count * 2; i += 2) {
			ctx.lineTo(x + i * width, y);
			ctx.lineTo(x + i * width, y - height);
			ctx.lineTo(x + (i + 1) * width, y - height);
			ctx.lineTo(x + (i + 1) * width, y);
		}
		ctx.stroke();

		ctx.beginPath();
		ctx.setLineDash([5, 8]);
		for (i = 1; i <= count * 2; i += 2) {
			ctx.moveTo(x + (i + 1) * width, y + 250);
			ctx.lineTo(x + (i + 1) * width, y + 250 + pin_enable_count * 80);
		}
		ctx.stroke();
		ctx.setLineDash([]);
	}
	function Slot_Waveform(ctx, x, y, width, height, slot_info, pin_info) {
		var x_pos = x,
			y_pos = y,
			repeat_start,
			repeat_end,
			repeat_count,
			whole_slot_repeat_count,
			i,
			j,
			k;

		ctx.fillStyle = "black";
		ctx.beginPath();
		ctx.font="20px Arial";
		ctx.textBaseline = "middle";

		for (i = 0; i < slot_info.length; i += 1) {
			if (slot_info[i].SlotEnable) {
				ctx.textAlign = "left";
				ctx.fillText ("SC" + i, x - 50, y_pos + height / 2);

				if (slot_info[i].init_slot == 0 ||
					slot_info[i].end_slot == 0) {
					repeat_count = 0;
				}
				else {
					repeat_start = slot_info[i].init_slot - 1;
					repeat_end = slot_info[i].end_slot - 1;
					repeat_count = slot_info[i].loop_count;
				}

				if (slot_info[i].repeat_mode) {
					whole_slot_repeat_count = 50;
				}
				else {
					whole_slot_repeat_count = 1;
				}

				for (k = 0; k < whole_slot_repeat_count; k += 1) {
					for (j = 0; j < slot_info[i].slot_count.length; j += 1) {
						if (slot_info[i].slot_count[j] == 0)
							break;

						ctx.moveTo(x_pos, y_pos);
						ctx.lineTo(x_pos, y_pos + height);
						ctx.textAlign = "center";
						ctx.fillText ("Slot" + j, x_pos + slot_info[i].slot_count[j] * width, y_pos + height / 2);
						x_pos = x_pos + slot_info[i].slot_count[j] * width * 2;

						if (repeat_count > 0) {
							if (j == repeat_end) {
								j = repeat_start - 1
								repeat_count = repeat_count - 1;
							}
						}
					}
				}

				ctx.moveTo(x_pos, y_pos);
				ctx.lineTo(x_pos, y_pos + height);
			}
			else {
				ctx.textAlign = "left";
				ctx.fillText ("SC" + i + "  Disable", x - 50, y_pos + height / 2);
			}
			x_pos = x;
			y_pos = y_pos + height + 10;
		}
		ctx.stroke();
	}
	function Pin_Initial_Status(ctx, x, y, width, height, slot_info, pin_info) {
		var j,
			x_pos = x,
			y_pos = y;

		ctx.fillStyle = "black";
		ctx.font="20px Arial";
		ctx.textAlign = "center";
		ctx.textBaseline = "middle";
		ctx.fillText ("Pin", x_pos - 200, y_pos - height / 2);
		ctx.fillText ("Select", x_pos - 150, y_pos - height / 2);
		ctx.fillText ("Initial", x_pos - 70, y_pos - height / 2);
		ctx.fillText ("Interval", x_pos + 30, y_pos - height / 2);

		for (j = 0; j < pin_info.length; j += 1) {
			if (pin_info[j].PinEnable) {
				ctx.font="20px Arial";
				ctx.fillStyle = "black";
				ctx.fillText (j, x_pos - 200, y_pos + height / 2);
				ctx.fillText ("SC" + pin_info[j].SlotCtlSel, x_pos - 150, y_pos + height / 2);
				DrawInitStatus(ctx, x_pos - 110, y_pos + height / 4, 80, 20, pin_info[j].initial, pin_info[j].interval, slot_info[pin_info[j].SlotCtlSel].trg_src, pin_info[j].io_mode);
				x_pos = x;
				y_pos = y_pos + height + 10;
			}
		}
	}
	function Pin_Waveform(ctx, x, y, width, height, slot_info, pin_info, canvas_width) {
		var i,
			j,
			k,
			index,
			x_pos,
			y_pos,
			repeat_start,
			repeat_end,
			repeat_count,
			whole_slot_repeat_count,
			slot_length,
			interval_length,
			PreviousCPACT,
			Slot_ActionType = [0, 0, 0, 0, 0, 0, 0, 0],
			SlotCheckPointEnable = [0, 0, 0, 0, 0, 0, 0, 0],
			SLOT_MAX_COUNT = 8;

		x_pos = x;
		y_pos = y;
		//loop each pin
		for (i = 0; i < pin_info.length; i += 1) {
			//reset slot status and checkpoint
			for (j = 0; j < SLOT_MAX_COUNT; j += 1) {
				Slot_ActionType[j] = pin_info[i].initial;
				SlotCheckPointEnable[j] = 0;
			}

			//draw waveform if pin enable and io mode != input mode
			if (slot_info[pin_info[i].SlotCtlSel].SlotEnable &&
				pin_info[i].PinEnable &&
				pin_info[i].io_mode != 0) {

				//Check if checkpoint is match rules
				for (j = 0; j < SLOT_MAX_COUNT; j += 1) {
					if (pin_info[i].CPSLOT[j] == 0) {
						k = j;
						while(k < SLOT_MAX_COUNT) {
							pin_info[i].CPSLOT[k] = 0;
							pin_info[i].CPACT[k] = 0;
							k += 1;
						}
					}
				}

				//The correlated SLOT should be filled in order from SLOT0 to SLOT7, or the check point action will not be triggered.
				for (j = SLOT_MAX_COUNT - 1; j >= 0; j -= 1) {
					if (pin_info[i].CPSLOT[j] != 0) {
						k = j;
						while(k > 0) {
							if (pin_info[i].CPSLOT[k] > pin_info[i].CPSLOT[j]) {
								pin_info[i].CPSLOT[j] = 0;
								break;
							}
							k -= 1;
						}
					}
				}

				//If there are two check points that select the same SLOT, the pin will follow settings of the smaller check point number
				for (j = SLOT_MAX_COUNT - 1; j >= 0; j -= 1) {
					if (pin_info[i].CPSLOT[j] != 0) {
						index = pin_info[i].CPSLOT[j] - 1;
						Slot_ActionType[index] = pin_info[i].CPACT[j];
						SlotCheckPointEnable[index] = 1;
					}
				}

				//get slot setting of repeat mode
				if (slot_info[pin_info[i].SlotCtlSel].init_slot == 0 ||
					slot_info[pin_info[i].SlotCtlSel].end_slot == 0) {
					repeat_count = 0;
				}
				else {
					repeat_start = slot_info[pin_info[i].SlotCtlSel].init_slot - 1;
					repeat_end = slot_info[pin_info[i].SlotCtlSel].end_slot - 1;
					repeat_count = slot_info[pin_info[i].SlotCtlSel].loop_count;
				}

				if (slot_info[pin_info[i].SlotCtlSel].repeat_mode) {
					whole_slot_repeat_count = 50;
				}
				else {
					whole_slot_repeat_count = 1;
				}

				for (k = 0; k < whole_slot_repeat_count; k += 1) {
					//loop each slot
					for (j = 0;j < SLOT_MAX_COUNT; j += 1) {
						if (slot_info[pin_info[i].SlotCtlSel].slot_count[j] == 0)
							break;

						//keep previous slot status if not set checkpoint
						if (SlotCheckPointEnable[j] == 0 && j != 0)
							Slot_ActionType[j] = PreviousCPACT;

						//each slot length
						slot_length = slot_info[pin_info[i].SlotCtlSel].slot_count[j] * width;

						//draw checkpoint green line
						if (SlotCheckPointEnable[j])
						{
							ctx.strokeStyle = "rgba(50, 205, 50, 1)";
							ctx.lineWidth = 5;
							ctx.beginPath();
							ctx.moveTo(x_pos, y_pos);
							ctx.lineTo(x_pos, y_pos + height);
							ctx.stroke();
							ctx.lineWidth = 1;
						}

						//status of each slot
						switch(Slot_ActionType[j])
						{
						case 0:
							ctx.strokeStyle = "black";
							ctx.lineWidth = 5;
							ctx.beginPath();
							ctx.moveTo(x_pos, y_pos + height);
							ctx.lineTo(x_pos + slot_length, y_pos + height);
							ctx.stroke();
							ctx.lineWidth = 1;
							break;
						case 1:
							ctx.strokeStyle = "black";
							ctx.lineWidth = 5;
							ctx.beginPath();
							ctx.moveTo(x_pos, y_pos);
							ctx.lineTo(x_pos + slot_length, y_pos);
							ctx.stroke();
							ctx.lineWidth = 1;
							break;
						case 2:
							DrawHexagon(ctx, x_pos + slot_length / 2, y_pos + height / 2, slot_length, height, "rgba(205, 85, 85, 1)", "DO")
							break;
						case 3:
							DrawHexagon(ctx, x_pos + slot_length / 2, y_pos + height / 2, slot_length, height, "rgba(205, 85, 85, 1)", "TO")
							break;
						case 4:
							DrawHexagon(ctx, x_pos + slot_length / 2, y_pos + height / 2, slot_length, height, "rgba(100, 149, 237, 1)", "DI")
							break;
						case 5:
							DrawHexagon(ctx, x_pos + slot_length / 2, y_pos + height / 2, slot_length, height, "rgba(100, 149, 237, 1)", "INSTS")
							break;
						case 6:
							DrawHexagon(ctx, x_pos + slot_length / 2, y_pos + height / 2, slot_length, height, "rgba(100, 149, 237, 1)", "INSTSUP")
							break;
						}
						x_pos = x_pos + slot_length;
						PreviousCPACT = Slot_ActionType[j];

						//back to repeat start slot of repeat mode
						if (repeat_count > 0) {
							if (j == repeat_end) {
								j = repeat_start - 1
								repeat_count = repeat_count - 1;
								PreviousCPACT = Slot_ActionType[j];
							}
						}
					}
				}

				if (slot_info[pin_info[i].SlotCtlSel].repeat_mode == 0) {
					if (canvas_width > x_pos) {
						interval_length = canvas_width - x_pos;
						//draw interval status waveform
						switch(pin_info[i].interval)
						{
						case 0:
							ctx.strokeStyle = "black";
							ctx.lineWidth = 5;
							ctx.beginPath();
							ctx.moveTo(x_pos, y_pos + height);
							ctx.lineTo(x_pos + interval_length, y_pos + height);
							ctx.stroke();
							ctx.lineWidth = 1;
							break;
						case 1:
							ctx.strokeStyle = "black";
							ctx.lineWidth = 5;
							ctx.beginPath();
							ctx.moveTo(x_pos, y_pos);
							ctx.lineTo(x_pos + interval_length, y_pos);
							ctx.stroke();
							ctx.lineWidth = 1;
							break;
						case 2:
							DrawHexagon(ctx, x_pos + interval_length / 2, y_pos + height / 2, interval_length, height, "rgba(205, 85, 85, 1)", "DO")
							break;
						case 3:
							DrawHexagon(ctx, x_pos + interval_length / 2, y_pos + height / 2, interval_length, height, "rgba(205, 85, 85, 1)", "TO")
							break;
						}
					}
				}
			}
			x_pos = x
			if (pin_info[i].PinEnable) {
				y_pos = y_pos + height + 10;
			}
		}
	}
	function DrawHexagon(ctx, x, y, width, height, color, text) {
		ctx.beginPath();
		ctx.moveTo(x - width / 2, y);
		ctx.lineTo(x - width / 2 + 10, y - height / 2);
		ctx.lineTo(x + width / 2 - 10, y - height / 2);
		ctx.lineTo(x + width / 2, y);
		ctx.lineTo(x + width / 2 - 10, y + height / 2);
		ctx.lineTo(x - width / 2 + 10, y + height / 2);
		ctx.strokeStyle = color;
		ctx.fillStyle = color
		ctx.stroke();
		ctx.fill();
		ctx.fillStyle = "white";
		ctx.font="14px Arial";
		ctx.textAlign = "center";
		ctx.textBaseline = "middle";
		ctx.fillText(text, x, y);
	}
	function DrawRect(ctx, x, y, width, height, text, enable) {
		if (enable)
		{
			rect_color = "rgba(135, 206, 250, 1)";
			text_color = "blue"
		}
		else
		{
			rect_color = "rgba(135, 206, 250, 0.1)";
			text_color = "grey"
		}
		ctx.font="14px Arial";
		ctx.textAlign = "center";
		ctx.textBaseline = "middle";
		width = ctx.measureText(text).width + 10;
		ctx.fillStyle = rect_color;
		ctx.fillRect(x, y, width, height);
		ctx.fillStyle = text_color;
		ctx.fillText(text, x + width / 2, y + height / 2);
		ctx.strokeRect(x, y, width, height);
		return width;
	}
	function DrawArrow(ctx, x, y) {
		ctx.fillStyle = "black"
		ctx.font="14px Arial";
		ctx.textAlign = "center";
		ctx.textBaseline = "middle";
		ctx.fillText(" >>> ", x, y);
	}
	function DrawInitStatus(ctx, x, y, width, height, init_index, interval_index, TrigSrc, IOMode) {
		var x_pos;

		ctx.fillStyle = "Black";
		ctx.font="14px Arial";
		ctx.textAlign = "center";
		ctx.textBaseline = "middle"
		//initial state
		ctx.fillText("L", x + width / 8, y - height / 2);
		ctx.strokeRect(x, y, width / 4, height);
		ctx.fillText("H", x + width * 3 / 8, y - height / 2);
		ctx.strokeRect(x + width / 4, y, width / 4, height);
		ctx.fillText("O", x + width * 5 / 8, y - height / 2);
		ctx.strokeRect(x + width / 2, y, width / 4, height);
		ctx.fillText("T", x + width * 7 / 8, y - height / 2);
		ctx.strokeRect(x + width * 3 / 4, y, width / 4, height);
		ctx.fillRect(x + width * init_index / 4, y, width / 4, height);

		//trigger source
		switch(TrigSrc)
		{
		case 0:
			ctx.fillText("SW", x + width / 2, y + height * 6 / 4);
			break;
		case 1:
			ctx.fillText("\\/", x + width / 2, y + height * 6 / 4);
			break;
		case 2:
			ctx.fillText("/\\", x + width / 2, y + height * 6 / 4);
			break;
		case 3:
			ctx.fillText("/\\  \\/", x + width / 2, y + height * 6 / 4);
			break;
		}
		ctx.strokeRect(x, y + height, width, height);

		x_pos = x + width * 10 / 8;
		//interval state
		ctx.fillText("L", x_pos + width / 8, y - height / 2);
		ctx.strokeRect(x_pos, y, width / 4, height);
		ctx.fillText("H", x_pos + width * 3 / 8, y - height / 2);
		ctx.strokeRect(x_pos + width / 4, y, width / 4, height);
		ctx.fillText("O", x_pos + width * 5 / 8, y - height / 2);
		ctx.strokeRect(x_pos + width / 2, y, width / 4, height);
		ctx.fillText("T", x_pos + width * 7 / 8, y - height / 2);
		ctx.strokeRect(x_pos + width * 3 / 4, y, width / 4, height);
		ctx.fillRect(x_pos + width * interval_index / 4, y, width / 4, height);

		//IO mode
		switch(IOMode)
		{
		case 0:
			ctx.fillText("Input", x_pos + width / 2, y + height * 6 / 4);
			break;
		case 1:
			ctx.fillText("Output", x_pos + width / 2, y + height * 6 / 4);
			break;
		case 2:
			ctx.fillText("OpenDrain", x_pos + width / 2, y + height * 6 / 4);
			break;
		case 3:
			ctx.fillText("Quasi", x_pos + width / 2, y + height * 6 / 4);
			break;
		}
		ctx.strokeRect(x_pos, y + height, width, height);
	}
	///////////////////////////////////////////////////////////public API/////////////////////////////////////////////////////////////
	NUTOOL_PER.drawCanvas = DrawCanvas;
}(NUTOOL_PER, this));
